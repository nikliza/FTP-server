#pragma once

namespace FtpServer
{  
    enum class FileTransferType  // Формат передачи данных
    {
        A,  // ASCII
        I,  // Бинарный
        E,  // Расширенный
        L,  // Локальный
        Unknown
    };
}