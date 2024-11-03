cmake_minimum_required(VERSION 3.28)
project(GeMo)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/parser)
include_directories(${CMAKE_SOURCE_DIR}/parser/ast)

add_executable(GeMo
        main.cpp
        coreGM.h
        parser/lexer/lexer.cpp
        parser/lexer/lexer.h
        parser/parser.cpp
        Generator/code_generator.cpp
        Generator/bytecode.cpp
)
