#pragma once

namespace FtpServer
{  
    enum class FileTransferMode  // Тип ftp подключения для данных
    {
        Active,  // Активное
        Passive  // Пассивное
    };
}