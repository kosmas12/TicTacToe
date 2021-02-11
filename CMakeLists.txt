cmake_minimum_required(VERSION 3.16)
project(TicTacToe)
set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)

set(SOURCE_FILES main.c)
set(SOURCE_FILES ${SOURCE_FILES} include/graphics.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
include_directories(${SDL2_INCLUDE_DIRS})


target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
