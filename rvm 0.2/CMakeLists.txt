cmake_minimum_required(VERSION 3.28)
project(Rylang C)

set(CMAKE_C_STANDARD 11)

add_executable(Rylang main.c
        scr/vm.c
        scr/gc.c)
