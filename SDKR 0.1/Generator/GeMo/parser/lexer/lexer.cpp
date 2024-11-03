#include "lexer.h"

Lexer::Lexer(const std::string& input) : input(input), index(0) {}

Token Lexer::nextToken() {
    while (index < input.size()) {
        char current = input[index];

        if (std::isspace(current)) {
            index++;
            continue;
        }
        if (std::isdigit(current)) {
            return number();
        }
        if (current == '+') {
            index++;
            return { TokenType::Plus, "+" };
        }
        if (current == '-') {
            index++;
            return { TokenType::Minus, "-" };
        }
        break;
    }
    return { TokenType::End, "" };
}

Token Lexer::number() {
    size_t start = index;
    while (index < input.size() && std::isdigit(input[index])) {
        index++;
    }
    return { TokenType::Number, input.substr(start, index - start) };
}
