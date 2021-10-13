#pragma once

#include <string>

namespace FtpServer
{
    class TcpClient  // TcpClient
    {
    private:
        int socket;  // Идентефикатор сокета
        bool alive;

    public:
        TcpClient();  // Конструктор по умолчанию
        TcpClient(int socket);  // Конструктор из сокета
        bool send(char* buffer, int size);  // Отослать массив байт
        bool sendString(std::string value);  // Отослать строку
        std::string acceptString();  // Получить строку
        void close();  // Закрыть сокет
        int amountData();  // Количество данных доступныз для получения
        bool isCorrect();  // Создан ли клиент (сокет не равен -1)
    };
}