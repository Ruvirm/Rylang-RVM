#include <stdlib.h>
#include <stdio.h>
#include "gc.h"

void allocHeap(VM *vm, int index, size_t size) {
    if (index < 0 || index >= HEAP_SIZE) {
        fprintf(stderr, "Ошибка: индекс вне границ кучи\n");
        freeVM(vm);
        exit(1);
    }
    if (vm->heap[index] != NULL) {
        free(vm->heap[index]);
    }
    vm->heap[index] = malloc(size);
    if (!vm->heap[index]) {
        fprintf(stderr, "Ошибка: не удалось выделить память\n");
        freeVM(vm);
        exit(1);
    }
}

void freeHeap(VM *vm, int index) {
    if (index < 0 || index >= HEAP_SIZE || !vm->heap[index]) {
        fprintf(stderr, "Ошибка: неверный индекс для освобождения памяти\n");
        freeVM(vm);
        exit(1);
    }
    free(vm->heap[index]);
    vm->heap[index] = NULL;
}
