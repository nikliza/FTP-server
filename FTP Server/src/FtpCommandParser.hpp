#pragma once

#include "FtpCommand.hpp"
#include "FtpAuthMethod.hpp"
#include "FileTransferType.hpp"

#include <string>
#include <vector>

namespace FtpServer
{
    class FtpCommandParser  // Парсер ftp команд
    {
    public:
        static FtpCommand parseCommand(std::string command);  // Распознать команду
        static FtpAuthMethod parseAuthMethod(std::string method);  // Распознать метод авторизации
        static FileTransferType parseFileTransferType(std::string method);  // Распознать тип подключения передачи данных
        static std::string getOsName();  // Получить нащвание операционной системы
        static std::vector<std::string> parse(std::string line);  // Распознать строку команды
    };
}