#pragma once

namespace FtpServer
{  
    enum class FtpAuthMethod  // Метод авторизации
    {
        SSL,  // Защищенное SLL
        TLS,  // Защищенное TLS
        Unknown
    };
}