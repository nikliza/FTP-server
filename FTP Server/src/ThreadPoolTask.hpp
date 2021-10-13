#pragma once

namespace FtpServer
{
    class ThreadPoolTask  // Абстрактный класс задачи пула потоков
    {
        public:
            virtual void run() = 0;  // Выполнение
            virtual ~ThreadPoolTask() {};  // Деструктор
    };
}