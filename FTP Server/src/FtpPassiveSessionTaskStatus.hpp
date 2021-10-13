#pragma once

namespace FtpServer
{  
    enum FtpPassiveSessionTaskStatus  // Статус выполненной задачи
    {
        Success,  // Успешно
        SendingError,  // Ошибка отправки
        ReadingFileError,  // Ошибка чтения файла
        ConnectionTimedOut
    };
}