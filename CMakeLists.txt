cmake_minimum_required(VERSION 3.21)
project(task4)

set(CMAKE_CXX_STANDARD 14)

add_executable(task4 main.cpp)

add_executable(backtrack backtrack.cpp)
add_executable(position position.cpp)
add_executable(application application.cpp)
add_executable(main main.cpp)