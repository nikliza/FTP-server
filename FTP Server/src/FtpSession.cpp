#include "FtpSession.hpp"
#include "ThreadPool.hpp"
#include "FileTransferMode.hpp"
#include "FtpCommandParser.hpp"
#include "FtpPassiveSessionTaskStatus.hpp"

#include <stdio.h>
#include <vector>
#include <string>
#include <filesystem>
#include <sstream>
#include <functional>

FtpServer::FtpSession::FtpSession(TcpClient client, std::string path, std::string address)
{
    this->client = client;
    this->address = address;
    alive = true;
    globalPath = path;
    passivePort = 1024;
}

void FtpServer::FtpSession::run()
{
    FtpPassiveSessionTask* task = nullptr;
    FtpPassiveSession* passiveSession = nullptr;
    FileTransferType type = FileTransferType::I;
    FileTransferMode mode = FileTransferMode::Passive;
    std::filesystem::path localPath = "/";
    std::string user = "";
    std::string password = "";
    int d1, d2, d3, d4;
    sscanf(address.c_str(), "%d.%d.%d.%d", &d1, &d2, &d3, &d4);

    std::function<void()> onTaskComplite = [&]
    {
        switch (task->status)
        {
        case FtpPassiveSessionTaskStatus::Success:
            if(!client.sendString("226 Transfer complete.\r\n"))
            {
                alive = false;
                break;
            }
            break;
        case FtpPassiveSessionTaskStatus::ReadingFileError:
            if(!client.sendString("451 Requested action aborted. Local error in processing.\r\n"))
            {
                alive = false;
                break;
            }
            break;
        case FtpPassiveSessionTaskStatus::SendingError:
            if(!client.sendString("426 Connection closed; transfer aborted.\r\n"))
            {
                alive = false;
                break;
            }
            break;
        case FtpPassiveSessionTaskStatus::ConnectionTimedOut:
            if(!client.sendString("451 Connection timed out.\r\n"))
            {
                alive = false;
                break;
            }
            break;
        }
        task = nullptr;
    };

    if(client.sendString("220 FTP Server.\r\n"))
    {
        while (alive && ThreadPool::isAlive())
        {
            if (client.amountData() > 0)
            {
                auto line = client.acceptString();
                auto tokens = FtpServer::FtpCommandParser::parse(line);
                if (tokens.size() > 0)
                {
                    auto command = FtpServer::FtpCommandParser::parseCommand(tokens[0]);
                    switch (command)
                    {
                    case FtpCommand::Auth:
                    {
                        auto authMethod = FtpAuthMethod::Unknown;
                        if (tokens.size() > 1)
                            authMethod = FtpServer::FtpCommandParser::parseAuthMethod(tokens[1]);
                        switch (authMethod)
                        {
                        case FtpAuthMethod::SSL:
                        {
                            if(!client.sendString("534 Local policy on server does not allow TLS secure connections.\r\n"))
                            {
                                alive = false;
                                break;
                            }
                            break;
                        }
                        case FtpAuthMethod::TLS:
                        {
                            if(!client.sendString("534 Local policy on server does not allow TLS secure connections.\r\n"))
                            {
                                alive = false;
                                break;
                            }
                            break;
                        }
                        case FtpAuthMethod::Unknown:
                        {
                            break;
                        }
                        }
                        break;
                    }
                    case FtpCommand::User:
                    {
                        if (tokens.size() > 1)
                        {
                            user = tokens[1];
                            if (user == "anonymous")
                            {
                                if(!client.sendString("331 Anonymous access allowed, send identity (e-mail name) as password.\r\n"))
                                {
                                    alive = false;
                                    break;
                                }
                            }
                            else if(!client.sendString("534 Local policy on server does not allow TLS secure connections.\r\n"))
                            {
                                alive = false;
                                break;
                            }
                        }
                        else if(!client.sendString("501 Syntax error in parameters or arguments.\r\n"))
                        {
                            alive = false;
                            break;
                        }
                        break;
                    }
                    case FtpCommand::Pass:
                    {
                        if (tokens.size() > 1)
                        {
                            password = tokens[1];
                            if (user != "" && password != "")
                            {
                                if(!client.sendString("230 User logged in.\r\n"))
                                {
                                    alive = false;
                                    break;
                                }
                            }
                        }
                        else if(!client.sendString("501 Syntax error in parameters or arguments.\r\n"))
                        {
                            alive = false;
                            break;
                        }
                        break;
                    }
                    case FtpCommand::Syst:
                    {
                        if(!client.sendString("215 " + FtpServer::FtpCommandParser::getOsName() + "\r\n"))
                        {
                            alive = false;
                            break;
                        }
                        break;
                    }
                    case FtpCommand::Feat:
                    {
                        if(!client.sendString("211-Features:\r\n") ||
                            !client.sendString("USER\r\n") ||
                            !client.sendString("PASS\r\n") ||
                            !client.sendString("LIST\r\n") ||
                            !client.sendString("PWD\r\n") ||
                            !client.sendString("TYPE\r\n") ||
                            !client.sendString("SYST\r\n") ||
                            !client.sendString("PASV\r\n") ||
                            !client.sendString("RETR\r\n") ||
                            !client.sendString("QUIT\r\n") ||
                            !client.sendString("211 End\r\n"))
                        {
                            alive = false;
                            break;
                        }
                        break;
                    }
                    case FtpCommand::Pwd:
                    {
                        if(!client.sendString("257 \"" + localPath.string() + "\" is the current directory.\r\n"))
                        {
                            alive = false;
                            break;
                        }
                        break;
                    }
                    case FtpCommand::Type:
                    {
                        if (tokens.size() > 1)
                        {
                            auto newType = FtpServer::FtpCommandParser::parseFileTransferType(tokens[1]);
                            if (newType != FileTransferType::Unknown)
                            {
                                type = newType;
                                if(!client.sendString("200 Type set to " + tokens[1] + "\r\n"))
                                {
                                    alive = false;
                                    break;
                                }
                            }
                            else if(!client.sendString("501 Syntax error in parameters or arguments.\r\n"))
                            {
                                alive = false;
                                break;
                            }
                        }
                        else if(!client.sendString("501 Syntax error in parameters or arguments.\r\n"))
                        {
                            alive = false;
                            break;
                        }
                        break;
                    }
                    case FtpCommand::Pasv:
                    {
                        mode = FileTransferMode::Passive;
                        int i = passivePort + 1;
                        for (; i < 49150; i++)
                            if (passiveListener.create(i))
                                break;
                        passiveListener.listen();
                        passivePort = i;
                        int low = passivePort / 256;
                        int hight = passivePort - (low * 256);
                        if(!client.sendString("227 Server set passive mode (" + std::to_string(d1) + ","  + std::to_string(d2)+","
                            + std::to_string(d3) + ","+std::to_string(d4) + "," + std::to_string(low) + "," + std::to_string(hight) + ")\r\n"))
                        {
                            alive = false;
                            break;
                        }
                        break;
                    }
                    case FtpCommand::List:
                    {
                        if (task == nullptr)
                        {
                            task = new FtpPassiveSessionTask();
                            task->command = FtpCommand::List;
                            task->path = globalPath;
                            task->path += localPath;
                            task->onComplite = onTaskComplite;

                            passiveSession = new FtpPassiveSession(task);
                            passiveSession->open(passiveListener);
                            ThreadPool::addTask(passiveSession);
                            if(!client.sendString((std::string)"150 Opening ASCII mode data connection.\r\n"))
                            {
                                alive = false;
                                break;
                            }
                        }
                        else if(!client.sendString("125 Data connection already open; transfer starting.\r\n"))
                        {
                            alive = false;
                            break;
                        }
                        break;
                    }
                    case FtpCommand::Retr:
                    {
                        if (task == nullptr)
                        {
                            if (tokens.size() > 1)
                            {
                                task = new FtpPassiveSessionTask();
                                auto file = tokens[1];
                                task->command = FtpCommand::Retr;
                                if (file[0] != '/')
                                {
                                    task->path = globalPath;
                                    task->path += localPath;
                                    task->path += "/" + file;
                                }
                                else
                                {
                                    task->path = globalPath;
                                    task->path += file;
                                }
                                task->onComplite = onTaskComplite;
            
                                passiveSession = new FtpPassiveSession(task);
                                passiveSession->open(passiveListener);
                                ThreadPool::addTask(passiveSession);
                                if(!client.sendString((std::string)"150 Opening " + (std::string)(type == FileTransferType::A ? "ASCII" : "BINARY") +
                                    (std::string)" mode data connection.\r\n"))
                                {
                                    alive = false;
                                    break;
                                }
                            }
                            else if(!client.sendString("501 Syntax error in parameters or arguments.\r\n"))
                            {
                                alive = false;
                                break;
                            }
                        }
                        else if(!client.sendString("125 Data connection already open; transfer starting.\r\n"))
                        {
                            alive = false;
                            break;
                        }
                        break;
                    }
                    case FtpCommand::Quit:
                    {
                        if(!client.sendString("221 The work has been successfully completed.\r\n"))
                        {
                            alive = false;
                            break;
                        }
                        break;
                    }
                    case FtpCommand::Cdup:
                    {
                        if (localPath.string().length() > 0 && (localPath.string().length() != 1 || localPath.string()[1] != '/'))
                            localPath = localPath.parent_path();
                        if(!client.sendString("250 Ok.\r\n"))
                        {
                            alive = false;
                            break;
                        }
                        break;
                    }
                    case FtpCommand::Cwd:
                    {
                        if (tokens.size() > 1)
                        {
                            auto toFolder = tokens[1];

                            while (true)
                            {
                                if (toFolder.length() >= 2 && toFolder.substr(0, 2) == "..")
                                {
                                    toFolder.erase(0, 2);
                                    if (localPath.string().length() > 0 && (localPath.string().length() != 1 || localPath.string()[1] != '/'))
                                        localPath = localPath.parent_path();
                                }
                                else if (toFolder.length() >= 3 && toFolder.substr(0, 3) == "/..")
                                {
                                    toFolder.erase(0, 3);
                                    if (localPath.string().length() > 0 && (localPath.string().length() != 1 || localPath.string()[1] != '/'))
                                        localPath = localPath.parent_path();
                                }
                                else
                                    break;
                            }

                            if (toFolder.length() > 0)
                            {
                                std::filesystem::path full = globalPath;
                                if (toFolder[0] != '/')
                                {
                                    full += localPath;
                                    full += "/" + toFolder;
                                }
                                else
                                    full += toFolder;
                                if (exists(full))
                                {
                                    if (std::filesystem::is_directory(full))
                                    {
                                        if (toFolder[0] != '/')
                                            localPath += "/" + toFolder;
                                        else
                                            localPath = toFolder;
                                        if(!client.sendString("250 Ok.\r\n"))
                                        {
                                            alive = false;
                                            break;
                                        }
                                    }
                                    else if(!client.sendString("550 " + full.string() + " is not a folder.\r\n"))
                                    {
                                        alive = false;
                                        break;
                                    }
                                }
                                else if(!client.sendString("550 " + full.string() + ": No such file or directory.\r\n"))
                                {
                                    alive = false;
                                    break;
                                }
                            }
                            else if(!client.sendString("250 Ok.\r\n"))
                            {
                                alive = false;
                                break;
                            }
                            break;
                        }
                    }
                    case FtpCommand::Unknown:
                    {
                        if(!client.sendString("502 Unknown command.\r\n"))
                        {
                            alive = false;
                            break;
                        }
                        break;
                    }
                    }
                }
            }
        }
    }
    client.close();
}

 FtpServer::FtpSession::~FtpSession()
 {

 }