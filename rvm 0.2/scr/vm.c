#include <stdio.h>
#include <stdlib.h>
#include "vm.h"
#include "gc.h"

void initVM(VM *vm, int *program) {
    vm->stack = malloc(STACK_SIZE * sizeof(int));
    if (!vm->stack) {
        fprintf(stderr, "Ошибка: не удалось выделить память для стека\n");
        exit(1);
    }
    for (int i = 0; i < HEAP_SIZE; i++) {
        vm->heap[i] = NULL;
    }
    vm->sp = -1;
    vm->pc = 0;
    vm->program = program;
}

void freeVM(VM *vm) {
    if (vm->stack) free(vm->stack);
    for (int i = 0; i < HEAP_SIZE; i++) {
        if (vm->heap[i]) free(vm->heap[i]);
    }
}

void push(VM *vm, int value) {
    if (vm->sp >= STACK_SIZE - 1) {
        fprintf(stderr, "Ошибка: переполнение стека\n");
        freeVM(vm);
        exit(1);
    }
    vm->stack[++vm->sp] = value;
}

int pop(VM *vm) {
    if (vm->sp >= 0) {
        return vm->stack[vm->sp--];
    } else {
        fprintf(stderr, "Ошибка: стек пуст\n");
        freeVM(vm);
        exit(1);
    }
}

void run(VM *vm) {
    int running = 1;
    while (running) {
        int instruction = vm->program[vm->pc++];

        switch (instruction) {
            case OP_NOP: break;
            case OP_PUSH: {
                int value = vm->program[vm->pc++];
                push(vm, value);
                break;
            }
            case OP_POP: pop(vm); break;
            case OP_IADD: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a + b);
                break;
            }
            case OP_ISUB: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a - b);
                break;
            }
            case OP_IMUL: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a * b);
                break;
            }
            case OP_IDIV: {
                int b = pop(vm);
                int a = pop(vm);
                if (b == 0) {
                    fprintf(stderr, "Ошибка: деление на ноль\n");
                    freeVM(vm);
                    exit(1);
                }
                push(vm, a / b);
                break;
            }
            case OP_IMOD: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a % b);
                break;
            }
            case OP_INC: vm->stack[vm->sp]++; break;
            case OP_DEC: vm->stack[vm->sp]--; break;
            case OP_AND: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a & b);
                break;
            }
            case OP_OR: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a | b);
                break;
            }
            case OP_NOT: vm->stack[vm->sp] = ~vm->stack[vm->sp]; break;
            case OP_XOR: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a ^ b);
                break;
            }
            case OP_SHL: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a << b);
                break;
            }
            case OP_SHR: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a >> b);
                break;
            }
            case OP_ILOAD: {
                int index = vm->program[vm->pc++];
                push(vm, vm->vars[index]);
                break;
            }
            case OP_ISTORE: {
                int index = vm->program[vm->pc++];
                vm->vars[index] = pop(vm);
                break;
            }
            case OP_NEW: {
                int index = vm->program[vm->pc++];
                int size = vm->program[vm->pc++];
                allocHeap(vm, index, size);
                break;
            }
            case OP_ALOAD: {
                int index = vm->program[vm->pc++];
                push(vm, (int)(size_t)vm->heap[index]);
                break;
            }
            case OP_ASTORE: {
                int index = vm->program[vm->pc++];
                vm->heap[index] = (void*)(size_t)pop(vm);
                break;
            }
            case OP_DUP: push(vm, vm->stack[vm->sp]); break;
            case OP_SWAP: {
                int a = pop(vm);
                int b = pop(vm);
                push(vm, a);
                push(vm, b);
                break;
            }
            case OP_ROT: {
                int a = pop(vm);
                int b = pop(vm);
                int c = pop(vm);
                push(vm, b);
                push(vm, a);
                push(vm, c);
                break;
            }
            case OP_IFEQ: {
                int addr = vm->program[vm->pc++];
                if (pop(vm) == 0) vm->pc = addr;
                break;
            }
            case OP_IFNE: {
                int addr = vm->program[vm->pc++];
                if (pop(vm) != 0) vm->pc = addr;
                break;
            }
            case OP_IFGT: {
                int addr = vm->program[vm->pc++];
                if (pop(vm) > 0) vm->pc = addr;
                break;
            }
            case OP_IFLT: {
                int addr = vm->program[vm->pc++];
                if (pop(vm) < 0) vm->pc = addr;
                break;
            }
            case OP_GOTO: {
                int addr = vm->program[vm->pc++];
                vm->pc = addr;
                break;
            }
            case OP_PRINT: {
                int value = pop(vm);
                printf("%d\n", value);
                break;
            }
            case OP_HALT:
                running = 0;
                break;
            default:
                fprintf(stderr, "Неизвестная команда: %d\n", instruction);
                running = 0;
                break;
        }
    }
}
