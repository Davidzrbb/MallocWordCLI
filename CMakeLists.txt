cmake_minimum_required(VERSION 3.20)
project(MallocWordCLI C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(MallocWordCLI
        include/include.h
        src/main.c)
