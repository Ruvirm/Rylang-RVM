#ifndef GC_H
#define GC_H

#include "vm.h"

void allocHeap(VM *vm, int index, size_t size);
void freeHeap(VM *vm, int index);

#endif // GC_H
