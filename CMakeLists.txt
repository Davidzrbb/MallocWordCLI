cmake_minimum_required(VERSION 3.20)
project(MallocWordCLI)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(MallocWordCLI
        .idea/.gitignore
        .idea/MallocWordCLI.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        include/include.h
        src/main.c
        src/PnjService.c)
