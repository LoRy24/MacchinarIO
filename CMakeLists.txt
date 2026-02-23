cmake_minimum_required(VERSION 3.20)
project(MacchinarIO C)

set(CMAKE_C_STANDARD 23)

add_executable(MacchinarIO
        src/program.c
        src/supremeio.c
        src/cypher.c
        src/data.c
        src/lists.c
        src/menus/main.c
        src/menus/commons.c
        src/accounts.c
        src/storage.c
        src/menus/accounts_view.c
        src/menus/register.c
        src/menus/delete.c
)

target_include_directories(MacchinarIO PRIVATE includes)