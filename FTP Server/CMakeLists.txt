project(ftp_server)
add_executable(ftp_server 
                src/String.cpp
                src/FtpCommandParser.cpp
                src/TcpClient.cpp
                src/TcpListener.cpp
                src/FtpSession.cpp
                src/FtpPassiveSession.cpp
                src/ThreadPool.cpp
                src/FtpServer.cpp
                src/main.cpp)

set (CMAKE_CXX_FLAGS  "-std=c++20")
set (CMAKE_EXE_LINKER_FLAGS  "-lpthread")