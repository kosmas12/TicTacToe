cmake_minimum_required(VERSION 3.16)
project(TicTacToe)
set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)

set(SOURCE_FILES main.c)
set(SOURCE_FILES ${SOURCE_FILES} include/graphics.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

include_directories(${SDL2_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS})

link_directories (${SDL2_LIBRARY_DIRS}
        ${SDL2_TTF_LIBRARY_DIRS})

target_link_libraries (${PROJECT_NAME}
        ${SDL2_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
