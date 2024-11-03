#ifndef BYTECODE_H
#define BYTECODE_H

#include <vector>

enum class ByteCode {
    Push,     // Поместить значение на стек
    Add,      // Сложить два значения
    Sub,      // Вычесть два значения
    Print,    // Вывести значение
    Halt      // Остановить выполнение
};

class ByteCodeGenerator {
public:
    void emit(ByteCode code, int operand = 0);
    const std::vector<int>& getCode() const;

private:
    std::vector<int> bytecode;
};

#endif // BYTECODE_H
