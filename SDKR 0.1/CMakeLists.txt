cmake_minimum_required(VERSION 3.28)
project(SDKR C)

set(CMAKE_C_STANDARD 11)

add_executable(SDKR

        main.c

        Vm/ByteCode/ByteCode.c
        core.h

)
