#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "vm.h" // Чтобы тип VM был определён

void *allocate_memory(size_t size);
void gc(VM *vm);

#endif
