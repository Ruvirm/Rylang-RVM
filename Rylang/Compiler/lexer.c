#include <stdio.h>
#include <ctype.h>
#include "compiler.h"


Token *lex(const char *source) {
    // Простая лексика для чисел и идентификаторов
    int i = 0;
    while (source[i] != '\0') {
        if (isdigit(source[i])) {
            printf("Найдено число: %c\n", source[i]);
        }
        i++;
    }
}
