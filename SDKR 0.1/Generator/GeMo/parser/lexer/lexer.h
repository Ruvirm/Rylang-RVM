#ifndef LEXER_H
#define LEXER_H

#include <string>

enum class TokenType {
    Number,
    Plus,
    Minus,
    End,
    Invalid
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    explicit Lexer(const std::string& input);
    Token nextToken();

private:
    std::string input;
    size_t index;
    Token number();
};

#endif // LEXER_H
