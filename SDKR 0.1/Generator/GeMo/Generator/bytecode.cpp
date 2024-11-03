#include "bytecode.h"

void ByteCodeGenerator::emit(ByteCode code, int operand) {
    bytecode.push_back(static_cast<int>(code));
    bytecode.push_back(operand);
}

const std::vector<int>& ByteCodeGenerator::getCode() const {
    return bytecode;
}
