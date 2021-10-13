#pragma once

#include "FtpCommand.hpp"
#include "TcpClient.hpp"
#include "TcpListener.hpp"
#include "ThreadPoolTask.hpp"
#include "FtpPassiveSessionTask.hpp"

#include <queue>
#include <string>
#include <mutex>

namespace FtpServer
{  
    class FtpPassiveSession : public ThreadPoolTask  // Сессия пассивного подключения (передачи данных)
    {
        private:
            FtpPassiveSessionTask* task;  // Задача
            TcpListener listener;  // Прослушиватель
            TcpClient client;  // Клиент
            bool alive;  // Выполняется ли сессия

        public:
            FtpPassiveSession(FtpPassiveSessionTask* task);  // Конструктор из задачи
            ~FtpPassiveSession();  // Деструктор
            void open(TcpListener listener);  // Открыть прослушивание
            virtual void run();  // Выполнение сессии
    };
}