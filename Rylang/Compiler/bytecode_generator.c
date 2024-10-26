#include "compiler.h"

int *generate_bytecode(Node *ast) {
    int *bytecode = malloc(sizeof(int) * 100);
    int i = 0;
    // Пример: Псевдо-код для генерации байт-кода
    bytecode[i++] = 0x01; // LOAD
    bytecode[i++] = 0x02; // ADD
    return bytecode;
}
