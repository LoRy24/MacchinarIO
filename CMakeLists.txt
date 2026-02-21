cmake_minimum_required(VERSION 4.0)
project(MacchinarIO C)

set(CMAKE_C_STANDARD 23)

add_executable(MacchinarIO src/main.c
        includes/supremeio.h
        src/supremeio.c
        includes/consolecolors.h
        includes/account.h)
