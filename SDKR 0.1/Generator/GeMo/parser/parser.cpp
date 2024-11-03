#include "parser.h"
#include <stdexcept>

Parser::Parser(Lexer& lexer) : lexer(lexer), currentToken(lexer.nextToken()) {}

int Parser::parse() {
    int result = expression();
    if (currentToken.type != TokenType::End) {
        throw std::runtime_error("Unexpected token");
    }
    return result;
}

void Parser::consume(TokenType type) {
    if (currentToken.type == type) {
        currentToken = lexer.nextToken();
    } else {
        throw std::runtime_error("Unexpected token");
    }
}

int Parser::expression() {
    int result = term();
    while (currentToken.type == TokenType::Plus || currentToken.type == TokenType::Minus) {
        Token op = currentToken;
        consume(op.type);
        int rhs = term();
        result = (op.type == TokenType::Plus) ? (result + rhs) : (result - rhs);
    }
    return result;
}

int Parser::term() {
    if (currentToken.type != TokenType::Number) {
        throw std::runtime_error("Expected number");
    }
    int value = std::stoi(currentToken.value);
    consume(TokenType::Number);
    return value;
}
