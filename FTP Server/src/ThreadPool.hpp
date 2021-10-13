#pragma once

#include "FtpSession.hpp"
#include "ThreadPoolTask.hpp"

#include <queue>
#include <mutex>
#include <vector>
#include <thread>
#include <functional>
#include <condition_variable>

namespace FtpServer
{
    class ThreadPool  // Пул потоков
    {
        private:
            static std::vector<std::thread> pool;  // Потоки
            static std::queue<ThreadPoolTask*> tasks;  // Задачи
            static std::mutex tasksMutex;  // Mutex для синхронизации
            static std::condition_variable condition;  // Условное выполнение
            static bool alive;  // Запущен ли
            static void threadHandler();  // Обработка потоков

        public:
            static void addTask(ThreadPoolTask* session);  // Добавить задачу
            static void start(int threadNumber = -1);  // Запустить
            static void stop();  // Остановить
            static int getThreadNumber();  // Количество потоков
            static bool isAlive();  // Запущен ли пул
    };
}