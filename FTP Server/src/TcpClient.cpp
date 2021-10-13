#include "TcpClient.hpp"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <sys/ioctl.h>

FtpServer::TcpClient::TcpClient()
{
    this->socket = -1;
}

FtpServer::TcpClient::TcpClient(int socket)
{
    this->socket = socket;
}

bool FtpServer::TcpClient::send(char* buffer, int size)
{
    if(::send(socket, buffer, size, 0) < 0)
        return false;
    return true;
}

bool FtpServer::TcpClient::sendString(std::string value)
{
    size_t size = sizeof(char) * (value.length());
    if(::send(socket, value.c_str(), size, 0) < 0)
        return false;
    return true;
}

int FtpServer::TcpClient::amountData()
{
    int count;
    ioctl(socket, FIONREAD, &count);
    return count;
}

std::string FtpServer::TcpClient::acceptString()
{
    std::string line;
    char buffer;
    int size;
    do 
    {
        int error = 0;
        socklen_t len = sizeof (error);
        int retval = getsockopt (socket, SOL_SOCKET, SO_ERROR, &error, &len);
        if (retval != 0) 
            break;
        if (error != 0)
            break;
        size = read(socket, &buffer, 1);
        if (size < 0)
            break;
        if (buffer == '\n')
        {
            line += buffer;
            break;
        }
        line += buffer;
    } while (size >= 0);
    return line;
}

void FtpServer::TcpClient::close()
{
    alive = false;
    ::close(socket);
}

bool FtpServer::TcpClient::isCorrect()
{
    return socket != -1;
}