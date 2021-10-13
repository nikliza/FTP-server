#pragma once

#include "TcpListener.hpp"
#include "ThreadPool.hpp"
#include <string>
#include <thread>

namespace FtpServer
{
    class FtpServer  // FTP сервер
    {
        private:
            std::string path;  // Путь к папке (root)
            TcpListener listener;  // Прослушиватель
            ThreadPool pool;  // Потоки
            std::thread* listeningThread;  // Поток прослушивания
            std::string address;  // Адрес сервера
            int threadNumber;  // Количество потоков
            int port;  // Порт FTP сервера
            bool alive;  // Запущен ли сервер

            void listening();  // Прослушивание

        public:
            FtpServer(std::string path, std::string address, int port, int threadNumber);  // Конструктор из пути, порта и количества потоков

            bool start();  // Запуск сервера
            void stop();  // Ост ановку сервера
    };
}