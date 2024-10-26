cmake_minimum_required(VERSION 3.10)
project(Rylang)

set(CMAKE_C_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/VM)
include_directories(${CMAKE_SOURCE_DIR}/Compiler)
include_directories(${CMAKE_SOURCE_DIR}/Preprocessor)
include_directories(${CMAKE_SOURCE_DIR}/SDK)

# Добавьте все исходные файлы проекта
add_executable(Rylang
        main.c
        VM/core_vm.c
        VM/memory_manager.c
        VM/vm.h
        VM/debugger.c
        Compiler/lexer.c
        Compiler/parser.c
        Compiler/bytecode_generator.c
        Compiler/compiler.h
        Preprocessor/preprocessor.c
        Preprocessor/preprocessor.h
        SDK/stdlib_rvm.c
        SDK/tools.c
        SDK/sdk.h
        VM/memory_manager.h
        VM/debugger.h

)
