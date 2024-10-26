#ifndef VM_H
#define VM_H

// Определение структуры VM
typedef struct {
    int *stack;
    int stack_size;
    int pc; // Программный счётчик
} VM;

// Объявления функций
VM *init_vm(int stack_size);
void execute(VM *vm, int *bytecode, int bytecode_size);

#endif
