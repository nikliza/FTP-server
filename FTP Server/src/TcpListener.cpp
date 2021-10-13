#include "TcpClient.hpp"
#include "TcpListener.hpp"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>

FtpServer::TcpListener::TcpListener()
{
    listener = -1;
}

FtpServer::TcpListener::TcpListener(int port)
{   
    if(!create(port))
    {
        exit(1);
    }
}

bool FtpServer::TcpListener::create(int port)
{
    struct sockaddr_in address;

    listener = socket(AF_INET, SOCK_STREAM, 0);

    if(listener < 0)
        return false;

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(listener, (struct sockaddr *)&address, sizeof(address)) < 0)
        return false;
    
    return true;
}

void FtpServer::TcpListener::listen()
{
    ::listen(listener, 1);
}

void FtpServer::TcpListener::stop()
{
    alive = false;
    close(listener);
}

FtpServer::TcpClient FtpServer::TcpListener::acceptTcpClient()
{
    struct timeval tv;

    tv.tv_sec = 1;
    tv.tv_usec = 0;

    FD_ZERO(&fds);
    FD_SET(listener, &fds);

    if (select(16, &fds, NULL, NULL, &tv) > 0)
        if (FD_ISSET(listener, &fds))
            return TcpClient(accept(listener, NULL, NULL));

    return TcpClient(-1);
}