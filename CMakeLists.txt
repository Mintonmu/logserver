cmake_minimum_required(VERSION 3.10)

# Set the project name
project(LogServer)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the executable
add_executable(LogServer src/main.cpp src/stream.cpp)

# Include directories (if needed)
target_include_directories(LogServer PUBLIC inc/)

# Link libraries (if needed)
# target_link_libraries(LogServer PRIVATE some_library)