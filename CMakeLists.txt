cmake_minimum_required(VERSION 2.8)

# Set the project name
project(BankApp)

# Specify the C++ standard (C++11 is probably the highest available for CMake 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Add the executable
add_executable(BankApp main.cpp src/Bank.cpp src/Customer.cpp src/Account.cpp)

# Add the include directory
include_directories(src)
