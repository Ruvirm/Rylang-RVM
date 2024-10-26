#include <stdio.h>
#include "vm.h"
#include "compiler.h"
#include "preprocessor.h"
#include "sdk.h"

#ifdef _WIN32
#include <windows.h>
#endif

void UTF() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
}


int main() {
    UTF();
    // Инициализация VM
    VM *vm = init_vm(256);

    // Препроцессинг файла
    preprocess("example.gr");

    // Компиляция файла в байт-код
    const char *source_code = "int a = 5;";
    Token *tokens = lex(source_code);
    Node *ast = parse(tokens);
    int *bytecode = generate_bytecode(ast);

    // Выполнение байт-кода
    execute(vm, bytecode, 10);

    // Отладочная информация
    debug_info("Программа завершена");

    return 0;
}
