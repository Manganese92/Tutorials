cmake_minimum_required(VERSION 3.23)
project(sdl_test C)

set(CMAKE_C_STANDARD 17)

set(SDL2_LIB_DIR C:/msys64/mingw64/lib)
set(SDL2_INCLUDE_DIR C:/msys64/mingw64/include/SDL2)
set(SDL2_LIBRARY C:/msys64/mingw64/bin)

add_executable(sdl_test main.c)
