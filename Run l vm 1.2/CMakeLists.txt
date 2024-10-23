cmake_minimum_required(VERSION 3.10)
project(Run_l_vm)

# Указываем каталоги для поиска заголовков
include_directories(scr/h)

# Указываем файлы, которые нужно компилировать
add_executable(Run_l_vm
        main.c
        scr/lexer/lexer.c
        scr/lexer/token_printer.c

)
