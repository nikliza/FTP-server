#include "ThreadPool.hpp"

#include <chrono>

std::vector<std::thread> FtpServer::ThreadPool::pool;
std::queue<FtpServer::ThreadPoolTask*> FtpServer::ThreadPool::tasks;
std::mutex FtpServer::ThreadPool::tasksMutex;
std::condition_variable FtpServer::ThreadPool::condition;
bool FtpServer::ThreadPool::alive = false;

void FtpServer::ThreadPool::threadHandler()
{
    while (alive)
    {
        tasksMutex.lock();
        if (!tasks.empty())
        {
            auto task = tasks.front();
            tasks.pop();
            tasksMutex.unlock();
            task->run();
            delete task;
        }
        else
        {
            tasksMutex.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}

void FtpServer::ThreadPool::addTask(ThreadPoolTask* task)
{
    tasksMutex.lock();
    tasks.push(task);
    tasksMutex.unlock();
}

void FtpServer::ThreadPool::start(int threadNumber)
{
    alive = true;
    if (threadNumber == -1)
        threadNumber = std::thread::hardware_concurrency();
    for (int i = 0; i < threadNumber; i++)
        pool.push_back(std::thread(&FtpServer::ThreadPool::threadHandler));
}

void FtpServer::ThreadPool::stop()
{
    alive = false;
    for (int i = 0; i < pool.size(); i++)
        pool[i].join();
    pool.clear();
}

 int FtpServer::ThreadPool::getThreadNumber()
 {
     return pool.size();
 }

bool FtpServer::ThreadPool::isAlive()
{
    return alive;
}