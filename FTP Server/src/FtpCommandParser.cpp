#include "FtpCommandParser.hpp"
#include "String.hpp"
#include "FtpCommand.hpp"
#include "FtpAuthMethod.hpp"
#include "FileTransferType.hpp"

#include <sys/utsname.h>

// Распознать команду по тексту
FtpServer::FtpCommand FtpServer::FtpCommandParser::parseCommand(std::string command)
{
    if (String::toUpper(command) == "AUTH")
        return FtpServer::FtpCommand::Auth;
    if (String::toUpper(command) == "USER")
        return FtpServer::FtpCommand::User;
    if (String::toUpper(command) == "PASS")
        return FtpServer::FtpCommand::Pass;
    if (String::toUpper(command) == "SYST")
        return FtpServer::FtpCommand::Syst;
    if (String::toUpper(command) == "FEAT")
        return FtpServer::FtpCommand::Feat;
    if (String::toUpper(command) == "PWD")
        return FtpServer::FtpCommand::Pwd;
    if (String::toUpper(command) == "TYPE")
        return FtpServer::FtpCommand::Type;
    if (String::toUpper(command) == "PASV")
        return FtpServer::FtpCommand::Pasv;
    if (String::toUpper(command) == "QUIT")
        return FtpServer::FtpCommand::Quit;
    if (String::toUpper(command) == "LIST")
        return FtpServer::FtpCommand::List;
    if (String::toUpper(command) == "CWD")
        return FtpServer::FtpCommand::Cwd;
    if (String::toUpper(command) == "RETR")
        return FtpServer::FtpCommand::Retr;
    if (String::toUpper(command) == "CDUP")
        return FtpServer::FtpCommand::Cdup;
    return FtpServer::FtpCommand::Unknown;
}

// Рспознать метод авторизации
FtpServer::FtpAuthMethod FtpServer::FtpCommandParser::parseAuthMethod(std::string method)
{
    if (String::toUpper(method) == "SSL")
        return FtpServer::FtpAuthMethod::SSL;
    if (String::toUpper(method) == "TLS")
        return FtpServer::FtpAuthMethod::TLS;
    return FtpServer::FtpAuthMethod::Unknown;
}

// Распознать тип соединения передачи данных
FtpServer::FileTransferType FtpServer::FtpCommandParser::parseFileTransferType(std::string method)
{
    if (String::toUpper(method) == "A")
        return FtpServer::FileTransferType::A;
    if (String::toUpper(method) == "I")
        return FtpServer::FileTransferType::I;
    if (String::toUpper(method) == "E")
        return FtpServer::FileTransferType::E;
    if (String::toUpper(method) == "L")
        return FtpServer::FileTransferType::L;
    return FtpServer::FileTransferType::Unknown;
}

// Получить название операционной системы
std::string FtpServer::FtpCommandParser::getOsName()
{
    struct utsname uts;
    uname(&uts);
    return uts.sysname;
}

// Рампознать команду
std::vector<std::string> FtpServer::FtpCommandParser::parse(std::string line)
{
    std::vector<std::string> tokens;  // Токены
    std::string token;  // Текущий токен
    for(size_t i = 0; i <= line.length(); i++)  // Пройтись по всем символам
    {
        char c = i < line.length() ? line[i] : ' ';
        if(c == ' ' || c == '\n' || c == '\r')  // Если конец слова
        {
            tokens.push_back(token);  // Добавить токен
            if (tokens.size() == 1)
            {
                if (parseCommand(token) == FtpCommand::Cwd)
                {
                    tokens.push_back(line.substr(i + 1, line.length() - (i + 1) - 2));
                    break;
                }
            }
            token = "";
        }
        else if(c == '\"' )  // Если ковычка
        {
            i++;
            while(line[i] != '\"')  // Искать следующую ковычку
                token += line[i];
        }
        else
            token += c;
    }
    return tokens;
}