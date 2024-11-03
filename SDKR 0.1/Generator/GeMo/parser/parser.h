#ifndef PARSER_H
#define PARSER_H

#include "lexer/lexer.h"

class Parser {
public:
    explicit Parser(Lexer& lexer);
    int parse();

private:
    Lexer& lexer;
    Token currentToken;
    void consume(TokenType type);
    int expression();
    int term();
};

#endif // PARSER_H
