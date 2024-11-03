#include "coreGM.h"
#include <iostream>


int main() {
    UTF();
    std::string input;
    input = "37+65-24";
    Lexer lexer(input);
    Parser parser(lexer);
    CodeGenerator codeGen;
    ByteCodeGenerator& byteCodeGen = codeGen.getByteCodeGenerator(); // Здесь мы вызываем метод

    try {
        int result = parser.parse();
        codeGen.generate(result);
        codeGen.printByteCode(byteCodeGen);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}