#include <stdio.h>
#include "debugger.h"

void check_syntax(const char *code) {
    int braces = 0;
    int semicolons = 0;
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '{') braces++;
        if (code[i] == '}') braces--;
        if (code[i] == ';') semicolons++;
    }
    if (braces != 0) printf("Ошибка: Непарные фигурные скобки\n");
    if (semicolons < 1) printf("Ошибка: Пропущены точки с запятой\n");
}
