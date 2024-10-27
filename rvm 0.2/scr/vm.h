// vm.h
#ifndef VM_H
#define VM_H

#include <stddef.h>

#define STACK_SIZE 256
#define HEAP_SIZE 1024
#define VAR_COUNT 16

// Команды виртуальной машины
typedef enum {
    OP_NOP = 0x00,
    OP_PUSH, OP_POP, OP_IADD, OP_ISUB, OP_IMUL, OP_IDIV, OP_IMOD,
    OP_INC, OP_DEC, OP_AND, OP_OR, OP_NOT, OP_XOR, OP_SHL, OP_SHR,
    OP_ILOAD, OP_ISTORE, OP_NEW, OP_ALOAD, OP_ASTORE,
    OP_DUP, OP_SWAP, OP_ROT,
    OP_IFEQ, OP_IFNE, OP_IFGT, OP_IFLT, OP_GOTO,
    OP_PRINT, OP_HALT
} OpCode;

// Структура виртуальной машины
typedef struct {
    int *stack;            // Стек
    int sp;                // Указатель стека
    int *program;          // Программа теперь имеет тип int*
    int pc;                // Счётчик команд
    int vars[VAR_COUNT];   // Переменные
    void *heap[HEAP_SIZE]; // Куча для объектов
} VM;

// Функции виртуальной машины
void initVM(VM *vm, int *program);
void freeVM(VM *vm);
void push(VM *vm, int value);
int pop(VM *vm);
void run(VM *vm);

#endif // VM_H
