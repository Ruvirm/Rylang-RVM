#ifndef LEXER_H
#define LEXER_H

// Определение типов токенов
typedef enum {
    tab,
    space,
    NUMBER,
    IDENTIFIER,
    OPERATOR,
    COUT,
    IMPORT,
    VOID,
    MAIN,
    RETURN,
    IF,
    ELIF,
    ELSE,
    SWITCH,
    CASE,
    DEFAULT,
    FOR,
    WHILE,
    DO,
    CLASS,
    STRUCT,
    PUBLIC,
    PROTECTED,
    PRIVATE,
    INPUT,
    PREPROCESSOR,
    DEFINE,
    UNDEF,
    INT,
    STRING,
    FLOAT,
    DOUBLE,
    CHAR,
    BOOL,
    NULL_TOKEN,
    PTR_NULL,
    UNKNOWN
} TokenType;

// Структура для токена
typedef struct {
    TokenType type;
    char value[100];
} Token;

// Объявление функций
Token create_token(TokenType type, const char* start, int length);
TokenType check_keyword(const char* start, int length);
void lexer(const char* input);

#endif // LEXER_H
