# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/liza/Документы/FTP Server"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/liza/Документы/FTP Server"

# Include any dependencies generated for this target.
include CMakeFiles/ftp_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ftp_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ftp_server.dir/flags.make

CMakeFiles/ftp_server.dir/src/String.cpp.o: CMakeFiles/ftp_server.dir/flags.make
CMakeFiles/ftp_server.dir/src/String.cpp.o: src/String.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/liza/Документы/FTP Server/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ftp_server.dir/src/String.cpp.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ftp_server.dir/src/String.cpp.o -c "/home/liza/Документы/FTP Server/src/String.cpp"

CMakeFiles/ftp_server.dir/src/String.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ftp_server.dir/src/String.cpp.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/liza/Документы/FTP Server/src/String.cpp" > CMakeFiles/ftp_server.dir/src/String.cpp.i

CMakeFiles/ftp_server.dir/src/String.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ftp_server.dir/src/String.cpp.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/liza/Документы/FTP Server/src/String.cpp" -o CMakeFiles/ftp_server.dir/src/String.cpp.s

CMakeFiles/ftp_server.dir/src/FtpCommandParser.cpp.o: CMakeFiles/ftp_server.dir/flags.make
CMakeFiles/ftp_server.dir/src/FtpCommandParser.cpp.o: src/FtpCommandParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/liza/Документы/FTP Server/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ftp_server.dir/src/FtpCommandParser.cpp.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ftp_server.dir/src/FtpCommandParser.cpp.o -c "/home/liza/Документы/FTP Server/src/FtpCommandParser.cpp"

CMakeFiles/ftp_server.dir/src/FtpCommandParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ftp_server.dir/src/FtpCommandParser.cpp.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/liza/Документы/FTP Server/src/FtpCommandParser.cpp" > CMakeFiles/ftp_server.dir/src/FtpCommandParser.cpp.i

CMakeFiles/ftp_server.dir/src/FtpCommandParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ftp_server.dir/src/FtpCommandParser.cpp.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/liza/Документы/FTP Server/src/FtpCommandParser.cpp" -o CMakeFiles/ftp_server.dir/src/FtpCommandParser.cpp.s

CMakeFiles/ftp_server.dir/src/TcpClient.cpp.o: CMakeFiles/ftp_server.dir/flags.make
CMakeFiles/ftp_server.dir/src/TcpClient.cpp.o: src/TcpClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/liza/Документы/FTP Server/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ftp_server.dir/src/TcpClient.cpp.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ftp_server.dir/src/TcpClient.cpp.o -c "/home/liza/Документы/FTP Server/src/TcpClient.cpp"

CMakeFiles/ftp_server.dir/src/TcpClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ftp_server.dir/src/TcpClient.cpp.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/liza/Документы/FTP Server/src/TcpClient.cpp" > CMakeFiles/ftp_server.dir/src/TcpClient.cpp.i

CMakeFiles/ftp_server.dir/src/TcpClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ftp_server.dir/src/TcpClient.cpp.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/liza/Документы/FTP Server/src/TcpClient.cpp" -o CMakeFiles/ftp_server.dir/src/TcpClient.cpp.s

CMakeFiles/ftp_server.dir/src/TcpListener.cpp.o: CMakeFiles/ftp_server.dir/flags.make
CMakeFiles/ftp_server.dir/src/TcpListener.cpp.o: src/TcpListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/liza/Документы/FTP Server/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ftp_server.dir/src/TcpListener.cpp.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ftp_server.dir/src/TcpListener.cpp.o -c "/home/liza/Документы/FTP Server/src/TcpListener.cpp"

CMakeFiles/ftp_server.dir/src/TcpListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ftp_server.dir/src/TcpListener.cpp.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/liza/Документы/FTP Server/src/TcpListener.cpp" > CMakeFiles/ftp_server.dir/src/TcpListener.cpp.i

CMakeFiles/ftp_server.dir/src/TcpListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ftp_server.dir/src/TcpListener.cpp.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/liza/Документы/FTP Server/src/TcpListener.cpp" -o CMakeFiles/ftp_server.dir/src/TcpListener.cpp.s

CMakeFiles/ftp_server.dir/src/FtpSession.cpp.o: CMakeFiles/ftp_server.dir/flags.make
CMakeFiles/ftp_server.dir/src/FtpSession.cpp.o: src/FtpSession.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/liza/Документы/FTP Server/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ftp_server.dir/src/FtpSession.cpp.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ftp_server.dir/src/FtpSession.cpp.o -c "/home/liza/Документы/FTP Server/src/FtpSession.cpp"

CMakeFiles/ftp_server.dir/src/FtpSession.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ftp_server.dir/src/FtpSession.cpp.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/liza/Документы/FTP Server/src/FtpSession.cpp" > CMakeFiles/ftp_server.dir/src/FtpSession.cpp.i

CMakeFiles/ftp_server.dir/src/FtpSession.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ftp_server.dir/src/FtpSession.cpp.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/liza/Документы/FTP Server/src/FtpSession.cpp" -o CMakeFiles/ftp_server.dir/src/FtpSession.cpp.s

CMakeFiles/ftp_server.dir/src/FtpPassiveSession.cpp.o: CMakeFiles/ftp_server.dir/flags.make
CMakeFiles/ftp_server.dir/src/FtpPassiveSession.cpp.o: src/FtpPassiveSession.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/liza/Документы/FTP Server/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ftp_server.dir/src/FtpPassiveSession.cpp.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ftp_server.dir/src/FtpPassiveSession.cpp.o -c "/home/liza/Документы/FTP Server/src/FtpPassiveSession.cpp"

CMakeFiles/ftp_server.dir/src/FtpPassiveSession.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ftp_server.dir/src/FtpPassiveSession.cpp.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/liza/Документы/FTP Server/src/FtpPassiveSession.cpp" > CMakeFiles/ftp_server.dir/src/FtpPassiveSession.cpp.i

CMakeFiles/ftp_server.dir/src/FtpPassiveSession.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ftp_server.dir/src/FtpPassiveSession.cpp.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/liza/Документы/FTP Server/src/FtpPassiveSession.cpp" -o CMakeFiles/ftp_server.dir/src/FtpPassiveSession.cpp.s

CMakeFiles/ftp_server.dir/src/ThreadPool.cpp.o: CMakeFiles/ftp_server.dir/flags.make
CMakeFiles/ftp_server.dir/src/ThreadPool.cpp.o: src/ThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/liza/Документы/FTP Server/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ftp_server.dir/src/ThreadPool.cpp.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ftp_server.dir/src/ThreadPool.cpp.o -c "/home/liza/Документы/FTP Server/src/ThreadPool.cpp"

CMakeFiles/ftp_server.dir/src/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ftp_server.dir/src/ThreadPool.cpp.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/liza/Документы/FTP Server/src/ThreadPool.cpp" > CMakeFiles/ftp_server.dir/src/ThreadPool.cpp.i

CMakeFiles/ftp_server.dir/src/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ftp_server.dir/src/ThreadPool.cpp.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/liza/Документы/FTP Server/src/ThreadPool.cpp" -o CMakeFiles/ftp_server.dir/src/ThreadPool.cpp.s

CMakeFiles/ftp_server.dir/src/FtpServer.cpp.o: CMakeFiles/ftp_server.dir/flags.make
CMakeFiles/ftp_server.dir/src/FtpServer.cpp.o: src/FtpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/liza/Документы/FTP Server/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ftp_server.dir/src/FtpServer.cpp.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ftp_server.dir/src/FtpServer.cpp.o -c "/home/liza/Документы/FTP Server/src/FtpServer.cpp"

CMakeFiles/ftp_server.dir/src/FtpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ftp_server.dir/src/FtpServer.cpp.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/liza/Документы/FTP Server/src/FtpServer.cpp" > CMakeFiles/ftp_server.dir/src/FtpServer.cpp.i

CMakeFiles/ftp_server.dir/src/FtpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ftp_server.dir/src/FtpServer.cpp.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/liza/Документы/FTP Server/src/FtpServer.cpp" -o CMakeFiles/ftp_server.dir/src/FtpServer.cpp.s

CMakeFiles/ftp_server.dir/src/main.cpp.o: CMakeFiles/ftp_server.dir/flags.make
CMakeFiles/ftp_server.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/liza/Документы/FTP Server/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ftp_server.dir/src/main.cpp.o"
	/usr/bin/clang++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ftp_server.dir/src/main.cpp.o -c "/home/liza/Документы/FTP Server/src/main.cpp"

CMakeFiles/ftp_server.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ftp_server.dir/src/main.cpp.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/liza/Документы/FTP Server/src/main.cpp" > CMakeFiles/ftp_server.dir/src/main.cpp.i

CMakeFiles/ftp_server.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ftp_server.dir/src/main.cpp.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/liza/Документы/FTP Server/src/main.cpp" -o CMakeFiles/ftp_server.dir/src/main.cpp.s

# Object files for target ftp_server
ftp_server_OBJECTS = \
"CMakeFiles/ftp_server.dir/src/String.cpp.o" \
"CMakeFiles/ftp_server.dir/src/FtpCommandParser.cpp.o" \
"CMakeFiles/ftp_server.dir/src/TcpClient.cpp.o" \
"CMakeFiles/ftp_server.dir/src/TcpListener.cpp.o" \
"CMakeFiles/ftp_server.dir/src/FtpSession.cpp.o" \
"CMakeFiles/ftp_server.dir/src/FtpPassiveSession.cpp.o" \
"CMakeFiles/ftp_server.dir/src/ThreadPool.cpp.o" \
"CMakeFiles/ftp_server.dir/src/FtpServer.cpp.o" \
"CMakeFiles/ftp_server.dir/src/main.cpp.o"

# External object files for target ftp_server
ftp_server_EXTERNAL_OBJECTS =

ftp_server: CMakeFiles/ftp_server.dir/src/String.cpp.o
ftp_server: CMakeFiles/ftp_server.dir/src/FtpCommandParser.cpp.o
ftp_server: CMakeFiles/ftp_server.dir/src/TcpClient.cpp.o
ftp_server: CMakeFiles/ftp_server.dir/src/TcpListener.cpp.o
ftp_server: CMakeFiles/ftp_server.dir/src/FtpSession.cpp.o
ftp_server: CMakeFiles/ftp_server.dir/src/FtpPassiveSession.cpp.o
ftp_server: CMakeFiles/ftp_server.dir/src/ThreadPool.cpp.o
ftp_server: CMakeFiles/ftp_server.dir/src/FtpServer.cpp.o
ftp_server: CMakeFiles/ftp_server.dir/src/main.cpp.o
ftp_server: CMakeFiles/ftp_server.dir/build.make
ftp_server: CMakeFiles/ftp_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/liza/Документы/FTP Server/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ftp_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ftp_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ftp_server.dir/build: ftp_server

.PHONY : CMakeFiles/ftp_server.dir/build

CMakeFiles/ftp_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ftp_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ftp_server.dir/clean

CMakeFiles/ftp_server.dir/depend:
	cd "/home/liza/Документы/FTP Server" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/liza/Документы/FTP Server" "/home/liza/Документы/FTP Server" "/home/liza/Документы/FTP Server" "/home/liza/Документы/FTP Server" "/home/liza/Документы/FTP Server/CMakeFiles/ftp_server.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ftp_server.dir/depend

