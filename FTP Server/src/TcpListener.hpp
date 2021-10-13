#pragma once

#include "TcpClient.hpp"

namespace FtpServer
{
    class TcpListener  // Прослушиватель TCP
    {
    private:
        int listener;  // Сокет
        bool alive;  // Запущен ли
        fd_set fds;  

    public:
        TcpListener();  // Конструктор по умолчанию
        TcpListener(int port);  // Конструктор из порта

        bool create(int port);  // Создание прослушивателя
        void listen();  // Запуск прослушки
        void stop();  // Остановка прослушки

        TcpClient acceptTcpClient();  // Получение TCP клиента
    };
}