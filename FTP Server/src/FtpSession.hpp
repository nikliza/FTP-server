#pragma once

#include "TcpClient.hpp"
#include "TcpListener.hpp"
#include "ThreadPoolTask.hpp"
#include "FtpPassiveSession.hpp"

#include <vector>
#include <thread>
#include <string>

namespace FtpServer
{  
    class FtpSession : public ThreadPoolTask  // Ftp сессия
    {
        private:
            TcpClient client;  // Клиент
            std::filesystem::path globalPath;  // Путь к корневой папке
            std::string address;  // IP адрес сервера
            int passivePort;  // Порт пассивого соединения
            bool alive;  // Выполняется ли сессия
            TcpListener passiveListener;

        public:
            FtpSession(TcpClient client, std::string path, std::string address);  // Конструктор из TCP клиета
            ~FtpSession();  // Деструткор
            virtual void run();  // Выполнение сессии
    };
}