#include <stdio.h>
#include "ByteCode.h"

void initVM(VM *vm) {
    vm->sp = -1;
}

void push(VM *vm, int value) {
    vm->stack[++vm->sp] = value;
}

int pop(VM *vm) {
    return vm->stack[vm->sp--];
}

void run(VM *vm, int *code) {
    int ip = 0;
    while (1) {
        int instruction = code[ip++];
        switch (instruction) {
            case PUSH: {
                int value = code[ip++];
                push(vm, value);
                break;
            }
            case ADD: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a + b);
                break;
            }
            case SUB: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a - b);
                break;
            }
            case MUL: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a * b);
                break;
            }
            case DIV: {
                int b = pop(vm);
                int a = pop(vm);
                if (b != 0) {
                    push(vm, a / b);
                } else {
                    printf("Ошибка: деление на ноль\n");
                    return;
                }
                break;
            }
            case MOD: {
                int b = pop(vm);
                int a = pop(vm);
                if (b != 0) {
                    push(vm, a % b);
                } else {
                    printf("Ошибка: деление на ноль\n");
                    return;
                }
                break;
            }
            case PRINT: {
                int value = pop(vm);
                printf("%d\n", value);
                break;
            }
            case DUP: {
                int value = vm->stack[vm->sp];
                push(vm, value);
                break;
            }
            case DUPN: {
                int n = code[ip++];
                int value = vm->stack[vm->sp - n];
                push(vm, value);
                break;
            }
            case SWAP: {
                int a = pop(vm);
                int b = pop(vm);
                push(vm, a);
                push(vm, b);
                break;
            }
            case OVER: {
                int value = vm->stack[vm->sp - 1];
                push(vm, value);
                break;
            }
            case DROP: {
                pop(vm);
                break;
            }
            case AND: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a & b);
                break;
            }
            case OR: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a | b);
                break;
            }
            case NOT: {
                int a = pop(vm);
                push(vm, ~a);
                break;
            }
            case LT: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a < b);
                break;
            }
            case GT: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a > b);
                break;
            }
            case EQ: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a == b);
                break;
            }
            case GOTO: {
                int target = code[ip++];
                ip = target;
                break;
            }
            case IFZERO: {
                int target = code[ip++];
                if (pop(vm) == 0) {
                    ip = target;
                }
                break;
            }
            case IFPOS: {
                int target = code[ip++];
                if (pop(vm) > 0) {
                    ip = target;
                }
                break;
            }
            case IFNEG: {
                int target = code[ip++];
                if (pop(vm) < 0) {
                    ip = target;
                }
                break;
            }
            case HALT:
                return;
            default:
                printf("Неизвестная инструкция: %d\n", instruction);
                return;
        }
    }
}
