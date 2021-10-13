#include "FtpServer.hpp"
#include "ThreadPool.hpp"

#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <filesystem>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <functional>

namespace {
    std::function<void(int)> shutdownHandler;
    void signalHandler(int signal) { shutdownHandler(signal); }
}

int main(int argc, char* argv[])
{
    int port = 21;
    int threadNumber = -1;
    struct passwd *pw = getpwuid(getuid());
    std::string path = pw->pw_dir;
    std::string address = "127.0.0.1";

    for (int i = 1; i < argc; i++)
    {
        if (argv[i] == std::string("-p") || argv[i] == std::string("--port"))
        {
            if (i < argc - 1)
            {
                try 
                {
                    port = std::stoi(argv[i + 1]);
                    i++;
                }
                catch (...)
                {
                    std::cout << "Incorrect port number!.\n";
                    return 0;
                }
            }
            else
            {
                std::cout << "Port not entered!\n";
                return 0;
            }
        }
        else if (argv[i] == std::string("-pa") || argv[i] == std::string("--path"))
        {
            if (i < argc - 1)
            {
                if (std::filesystem::exists(argv[i + 1]))
                {
                    if (std::filesystem::is_directory(argv[i + 1]))
                    {
                        std::string pathString = argv[i + 1];
                        if (pathString == "/" || pathString == "\\")
                            pathString = "";
                        path = pathString;
                        i++;
                    }
                    else
                    {
                        std::cout << "Path is not a directory!\n";
                        return 0;
                    }
                }
                else
                {
                    std::cout << "Path not exists!\n";
                    return 0;
                }
            }
            else
            {
                std::cout << "Path not entered!\n";
                return 0;
            }
        }
        else if (argv[i] == std::string("-t") || argv[i] == std::string("--threads"))
        {
            if (i < argc - 1)
            {
                try 
                {
                    threadNumber = std::stoi(argv[i + 1]);
                    i++;
                }
                catch (...)
                {
                    std::cout << "Incorrect number of threads!.\n";
                    return 0;
                }
            }
            else
            {
                std::cout << "Number of threads not entered!\n";
                return 0;
            }
        }
        else if (argv[i] == std::string("-a") || argv[i] == std::string("--address"))
        {
            if (i < argc - 1)
            {
                try 
                {
                    struct sockaddr_in sa;
                    int result = inet_pton(AF_INET, argv[i + 1], &(sa.sin_addr));
                    if(result == 0)
                    {
                        std::cout << "Incorrect ip address!.\n";
                        return 0;
                    }
                    address = argv[i + 1];
                    i++;
                }
                catch (...)
                {
                    std::cout << "Incorrect ip address!.\n";
                    return 0;
                }
            }
            else
            {
                std::cout << "IP address not entered!\n";
                return 0;
            }
        }
        else if (argv[i] == std::string("-h") || argv[i] == std::string("--help"))
        {
            std::cout << "Help with FTP server operation:\n" <<
                "    -p  | --port    Setting the port for connection.\n" <<
                "    -pa | --path    Setting the path to the root directory.\n" <<
                "    -t  | --treads  Setting the number of task processing threads.\n\n";
            return 0;
        }
        else
        {
            std::cout << "Uncnown key: \"" << argv[i] << "\"!\n";
            return 0;
        }
    }


    FtpServer::FtpServer server(path, address, port, threadNumber);
    
    shutdownHandler = [&](int sig)
    {
        server.stop();
        std::cout << "\nFTP serrver stopped.\n";
        exit(0);
    };

    if(server.start())
    {
        signal(SIGINT, signalHandler); 
        std::cout << "FTP server is started.\n";
        std::cout << "Path to the root directory: \"" << path << "\".\n";
        std::cout << "Connection port: " << port << ".\n";
        std::cout << "Number of threads: " << FtpServer::ThreadPool::getThreadNumber() << ".\n";
        std::cout << "Press key to stop.";
        std::cin.get();
        server.stop();
        std::cout << "FTP serrver stopped.\n";
    }
    else
        std::cout << "Failed to start the FTP server on port: " << port << ".\n" <<
            "Try using a different port.\n";
    return 0;
}