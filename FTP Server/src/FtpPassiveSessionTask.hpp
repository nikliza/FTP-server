#pragma once

#include "FtpCommand.hpp"
#include "FtpPassiveSessionTaskStatus.hpp"

#include <string>
#include <filesystem>
#include <functional>

namespace FtpServer
{  
    struct FtpPassiveSessionTask  // Задача подключения передачи данных
    {
        FtpCommand command;  // Команда
        std::filesystem::path path;  // Путь
        std::string argument;  // Дополнительные аргументы
        std::function<void()> onComplite;  // Функция для выполнения после выполнения задачи
        FtpPassiveSessionTaskStatus status = FtpPassiveSessionTaskStatus::Success;  // Статус задачи
    };
}