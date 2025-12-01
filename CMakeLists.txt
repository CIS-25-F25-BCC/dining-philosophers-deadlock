cmake_minimum_required(VERSION 3.10)
project(dining-philosophers-deadlock)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(philosophers main.cpp)

# Threading support
find_package(Threads REQUIRED)
target_link_libraries(philosophers Threads::Threads)
