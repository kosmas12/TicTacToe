cmake_minimum_required(VERSION 3.16)
project(TicTacToe)
set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)

set(SOURCE_FILES main.c include/graphics.c include/input.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
pkg_check_modules(SDL2_IMG REQUIRED SDL2_image)

if(${CMAKE_HOST_APPLE})
    set(SDL2_TTF_LIBRARIES "-L${SDL2_LIBRARY_DIRS} -lSDL2_ttf")   
endif()

IF (${SDL2_FOUND})
    Message( STATUS "SDL2_LIBRARY: " ${SDL2_LIBRARIES})
    Message( STATUS "SDL2_INCLUDE_DIRS:" ${SDL2_INCLUDE_DIRS})
    Message( STATUS "SDL2_LIBRARY_DIRS:" ${SDL2_LIBRARY_DIRS})

    Message( STATUS "SDL2_TTF_LIBRARY: " ${SDL2_TTF_LIBRARIES})
    Message( STATUS "SDL2_TTF_INCLUDE_DIRS:" ${SDL2_TTF_INCLUDE_DIRS})
    Message( STATUS "SDL2_TTF_LIBRARY_DIRS: " ${SDL2_TTF_LIBRARY_DIRS})
    
    Message( STATUS "SDL2_IMG_LIBRARY: " ${SDL2_IMG_LIBRARIES})
    Message( STATUS "SDL2_IMG_INCLUDE_DIRS:" ${SDL2_IMG_INCLUDE_DIRS})
    Message( STATUS "SDL2_IMG_LIBRARY_DIRS: " ${SDL2_IMG_LIBRARY_DIRS})
ELSE()
    Message( STATUS "SDL2_FOUND: " ${SDL2_FOUND})
    Message( FATAL_ERROR "SDL2 NOT FOUND" )
ENDIF()


include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
    ${SDL2_IMG_INCLUDE_DIRS}
)

link_directories(
    ${SDL2_LIBRARY_DIRS}
    ${SDL2_TTF_LIBRARY_DIRS}
    ${SDL2_IMG_LIBRARY_DIRS}
)

target_link_libraries(
    ${PROJECT_NAME}
    ${SDL2_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${SDL2_IMG_LIBRARIES}
)


if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/O.png ${CMAKE_CURRENT_BINARY_DIR}/O.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/X.png ${CMAKE_CURRENT_BINARY_DIR}/X.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/cursor.png ${CMAKE_CURRENT_BINARY_DIR}/cursor.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/Serif.ttf ${CMAKE_CURRENT_BINARY_DIR}/Serif.ttf COPYONLY)
