#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "bytecode.h"
#include <iostream>

class CodeGenerator {
public:
    void generate(int result);
    void printByteCode(const ByteCodeGenerator& byteCodeGen);
    ByteCodeGenerator& getByteCodeGenerator(); // Обязательно добавьте этот метод

private:
    ByteCodeGenerator byteCodeGen;
};

#endif // CODE_GENERATOR_H
