#include <stdio.h>
#include "scr/vm.h"

// Настройка кодировки UTF-8 для Windows
#ifdef _WIN32
#include <windows.h>
void UTF() {
    SetConsoleOutputCP(CP_UTF8);
}
#else
void UTF() {}  // Пустая реализация для других ОС
#endif

int main() {
    UTF();  // Устанавливаем кодировку


    int program[] = {
        OP_PUSH, 510,
        OP_PUSH, 20,
        OP_IADD,
        OP_PRINT,
        OP_PUSH, 5190,
        OP_PUSH, 20,
        OP_IADD,
        OP_PRINT,
        OP_HALT
    };

    VM vm;
    initVM(&vm, program);
    run(&vm);
    freeVM(&vm);

    return 0;
}
