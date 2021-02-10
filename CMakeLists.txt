cmake_minimum_required(VERSION 3.16)
project(TicTacToe)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})