#include "code_generator.h"
#include <iostream>


void CodeGenerator::generate(int result) {
    byteCodeGen.emit(ByteCode::Push, result);
    byteCodeGen.emit(ByteCode::Print);
    byteCodeGen.emit(ByteCode::Halt);
}

void CodeGenerator::printByteCode(const ByteCodeGenerator& byteCodeGen) {
    const auto& code = byteCodeGen.getCode();
    std::cout << "Сгенерированный байт-код:\n";

    for (size_t i = 0; i < code.size(); i += 2) {
        ByteCode instruction = static_cast<ByteCode>(code[i]);
        int operand = code[i + 1];

        // Используем switch для определения названия операции
        std::string instructionName;
        switch (instruction) {
            case ByteCode::Push:
                instructionName = "Push";
            break;
            case ByteCode::Add:
                instructionName = "Add";
            break;
            case ByteCode::Sub:
                instructionName = "Sub";
            break;
            case ByteCode::Print:
                instructionName = "Print";
            break;
            case ByteCode::Halt:
                instructionName = "Halt";
            break;
        }

        std::cout << instructionName << " " << operand << " | ";
    }
    std::cout << std::endl;
}


ByteCodeGenerator& CodeGenerator::getByteCodeGenerator() {
    return byteCodeGen; // Реализация метода
}
