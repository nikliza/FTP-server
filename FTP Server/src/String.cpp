#include "String.hpp"

std::string FtpServer::String::toUpper(std::string value)
{
    std::string copy = value;
    for (auto & c: copy) 
        c = ::toupper(c);
    return copy;
}