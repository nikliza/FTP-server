#include "FtpServer.hpp"
#include "FtpSession.hpp"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <thread>
#include <chrono>

FtpServer::FtpServer::FtpServer(std::string path, std::string address, int port, int threadNumber)
{
    this->address = address;
    this->port = port;
    this->path = path;
    this->threadNumber = threadNumber;
}

bool FtpServer::FtpServer::start()
{
    if (!listener.create(port))
        return false;
    alive = true;
    ThreadPool::start(threadNumber);
    listeningThread = new std::thread(&FtpServer::FtpServer::listening, this);
    return true;
}

void FtpServer::FtpServer::stop()
{
    if (alive)
    {
        alive = false;
        listeningThread->join();
        ThreadPool::stop();
        delete listeningThread;
    }
}

void FtpServer::FtpServer::listening()
{
    listener.listen();
    while (alive)
    {
        auto client = listener.acceptTcpClient();
        if (client.isCorrect())
            ThreadPool::addTask(new FtpSession(client, path, address));
        else
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    listener.stop();
}
