#include "FtpPassiveSession.hpp"
#include "ThreadPool.hpp"
#include "FtpPassiveSessionTaskStatus.hpp"


#include <stdio.h>
#include <vector>
#include <string>
#include <sys/utsname.h>
#include <cstdio>
#include <sched.h>
#include <iostream>
#include <memory>
#include <sstream>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <filesystem>
#include <time.h>
 
FtpServer::FtpPassiveSession::FtpPassiveSession(FtpPassiveSessionTask* task)
{
    alive = true;
    this->task = task;
}

void FtpServer::FtpPassiveSession::open(TcpListener listener)
{
    this->listener = listener;
}

void FtpServer::FtpPassiveSession::run()
{
    TcpClient client;
    clock_t start, end;
    double cpuTmeUsed;
    start = clock();
    while (alive && ThreadPool::isAlive())
    {
        client = listener.acceptTcpClient();
        if (client.isCorrect())
        {
            break;
        }
        end = clock();
        cpuTmeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        if (cpuTmeUsed > 5.0)
        {
            task->status = FtpPassiveSessionTaskStatus::ConnectionTimedOut;
            alive = false;
            task->onComplite();
            break;
        }
    }
    listener.stop();
  
    if (alive && ThreadPool::isAlive())
    {
        switch (task->command)
        {
        case FtpCommand::Retr:
        {   
            if (exists(task->path))
            {
                std::ifstream file(task->path, std::ios::binary);
                char buffer[1450];
                file.seekg (0, file.end);
                int length = file.tellg();
                int tranfered = 0;
                file.seekg (0, file.beg);
                while (tranfered < length)
                {
                    int need = length - tranfered < 1450 ? length - tranfered : 1450;
                    file.read(buffer, need);
                    if(!file)
                    {
                        task->status = FtpPassiveSessionTaskStatus::ReadingFileError;
                        break;
                    }
                    if(!client.send(buffer, need))
                    {
                        task->status = FtpPassiveSessionTaskStatus::SendingError;
                        break;
                    }
                    tranfered += need;
                }
                file.close();
            }
            task->onComplite();
            break;
        }
        case FtpCommand::List:
        {
            std::stringstream stream;
            std::filesystem::path path = task->path;
            int sizeMaxLength = 0;
            for (const auto & entry : std::filesystem::directory_iterator(path))
            {
                if (!std::filesystem::is_directory(path))
                {
                    try 
                    {
                        int length = std::to_string(file_size(path)).length();
                        if(length > sizeMaxLength)
                            sizeMaxLength = length;
                    }
                    catch(std::filesystem::filesystem_error& e) 
                    {
                        if (sizeMaxLength < 1)
                            sizeMaxLength = 1;
                    }
                }
                else
                    if (sizeMaxLength < 4)
                        sizeMaxLength = 4;
            }

            #ifdef LINUX_LIST_OUT
            {
                for (const auto & entry : std::filesystem::directory_iterator(path))
                {
                    auto path = entry.path();
                    if (std::filesystem::is_directory(path))
                        stream << 'd';
                    else
                        stream << '-';

                    auto p = std::filesystem::status(entry.path()).permissions();
                    stream << ((p & std::filesystem::perms::owner_read) != std::filesystem::perms::none ? "r" : "-")
                    << ((p & std::filesystem::perms::owner_write) != std::filesystem::perms::none ? "w" : "-")
                    << ((p & std::filesystem::perms::owner_exec) != std::filesystem::perms::none ? "x" : "-")
                    << ((p & std::filesystem::perms::group_read) != std::filesystem::perms::none ? "r" : "-")
                    << ((p & std::filesystem::perms::group_write) != std::filesystem::perms::none ? "w" : "-")
                    << ((p & std::filesystem::perms::group_exec) != std::filesystem::perms::none ? "x" : "-")
                    << ((p & std::filesystem::perms::others_read) != std::filesystem::perms::none ? "r" : "-")
                    << ((p & std::filesystem::perms::others_write) != std::filesystem::perms::none ? "w" : "-")
                    << ((p & std::filesystem::perms::others_exec) != std::filesystem::perms::none ? "x" : "-")
                    << ' ';

                    stream << "1 ";

                    struct stat info;
                    stat(path.string().c_str(), &info);
                    struct passwd *pw = getpwuid(info.st_uid);
                    struct group  *gr = getgrgid(info.st_gid);
                    stream << pw->pw_name << ' ';
                    stream << gr->gr_name << ' ';

                    if (!std::filesystem::is_directory(path))
                    {
                        try 
                        {
                            stream << std::setw(sizeMaxLength) << file_size(path) << ' ';
                        }
                        catch(std::filesystem::filesystem_error& e) 
                        {
                            stream << std::setw(sizeMaxLength) << "0" << ' ';
                        }
                    }
                    else
                        stream << std::setw(sizeMaxLength) << "4196" << ' ';

                    char editedTimeMonth[5];
                    char editedTimeTime[7];
                    struct tm& dateTime = *gmtime(&(info.st_ctime));
                    strftime(editedTimeMonth, 5, "%b ", &dateTime);
                    strftime(editedTimeTime, 7, "%H:%M ", &dateTime);

                    stream << editedTimeMonth << std::setw(2) << dateTime.tm_mday << editedTimeTime;
                    stream << entry.path().filename().string() << "\r\n";
                }
            }
            #else
            {
                for (const auto & entry : std::filesystem::directory_iterator(path))
                {        
                    auto path = entry.path();    
                    struct stat info;
                    stat(path.string().c_str(), &info);
                    char editedDateTime[18];
                    struct tm& dateTime = *gmtime(&(info.st_ctime));
                    strftime(editedDateTime, 18, "%d-%m-%y %I:%M%p", &dateTime);
                    stream << editedDateTime << ' ';
                    
                    if (std::filesystem::is_directory(path))
                        stream << "<DIR> ";
                    else
                        stream << "      ";

                    if (!std::filesystem::is_directory(path))
                    {
                        try 
                        {
                            stream << std::setw(sizeMaxLength) << file_size(path) << ' ';
                        }
                        catch(std::filesystem::filesystem_error& e) 
                        {
                            stream << std::setw(sizeMaxLength) << "0" << ' ';
                        }
                    }
                    else
                        stream << std::setw(sizeMaxLength) << " " << ' ';

                    stream << entry.path().filename().string() << "\r\n";
                }
            }
            #endif

            if(!client.sendString(stream.str()))
                task->status = FtpPassiveSessionTaskStatus::SendingError;
            task->onComplite();
            break;
        }
        default:
            break;
        }
    }

    client.close();
}

FtpServer::FtpPassiveSession::~FtpPassiveSession()
{

}