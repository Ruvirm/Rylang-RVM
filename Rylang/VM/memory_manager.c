#include <stdlib.h>
#include <stdio.h>
#include "memory_manager.h"


void *allocate_memory(size_t size) {
    void *mem = malloc(size);
    if (!mem) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    return mem;
}

void gc(VM *vm) {
    // Простой механизм сборщика мусора (пример)
    printf("GC: Освобождение памяти...\n");
    // Логика освобождения памяти
}
