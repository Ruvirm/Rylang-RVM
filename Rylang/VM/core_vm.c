#include <stdio.h>
#include <stdlib.h>
#include "vm.h" // Включение заголовочного файла с определением VM и функциями
#include "memory_manager.h"
#include "debugger.h"

// Реализация функций init_vm и execute

VM *init_vm(int stack_size) {
    VM *vm = (VM *)malloc(sizeof(VM));
    vm->stack = (int *)malloc(sizeof(int) * stack_size);
    vm->stack_size = stack_size;
    vm->pc = 0;
    return vm;
}

void execute(VM *vm, int *bytecode, int bytecode_size) {
    while (vm->pc < bytecode_size) {
        int instruction = bytecode[vm->pc];
        switch (instruction) {
            case 0x01: // Н-р, LOAD
                vm->stack[vm->pc++] = bytecode[++vm->pc];
            break;
            case 0x02: // ADD
                vm->stack[vm->pc - 2] = vm->stack[vm->pc - 2] + vm->stack[vm->pc - 1];
            vm->pc--;
            break;
            default:
                printf("Неизвестная команда: %d\n", instruction);
            break;
        }
        vm->pc++;
    }
}
