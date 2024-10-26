#include <stdio.h>
#include <string.h>
#include "preprocessor.h"

void preprocess(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Не удалось открыть файл: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "#define")) {
            printf("Найден макрос: %s", line);
        }
    }
    fclose(file);
}
