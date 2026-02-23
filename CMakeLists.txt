cmake_minimum_required(VERSION 3.31.6)
project(MacchinarIO C)

set(CMAKE_C_STANDARD 23)

add_executable(MacchinarIO src/program.c
        includes/supremeio.h
        src/supremeio.c
        includes/consolecolors.h
        includes/accounts.h
        includes/cypher.h
        src/cypher.c
        src/data.c
        includes/data.h
        includes/lists.h
        includes/menus.h
        src/menus/main.c
        src/lists.c
        src/menus/commons.c
        src/accounts.c
        src/storage.c
        includes/storage.h
        src/menus/accounts_view.c
        src/menus/register.c
        src/menus/delete.c)