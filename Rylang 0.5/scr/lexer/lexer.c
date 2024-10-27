#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

// Функция для создания токена из строки
Token create_token(TokenType type, const char* start, int length) {
    Token token;
    token.type = type;
    strncpy(token.value, start, length);
    token.value[length] = '\0'; // Завершение строки
    return token;
}

// Функция для проверки ключевых слов и типов данных
TokenType check_keyword(const char* start, int length) {
    if (strncmp(start, "import", length) == 0) return IMPORT;
    if (strncmp(start, "void", length) == 0) return VOID;
    if (strncmp(start, "main", length) == 0) return MAIN;
    if (strncmp(start, "return", length) == 0) return RETURN;
    if (strncmp(start, "if", length) == 0) return IF;
    if (strncmp(start, "elif", length) == 0) return ELIF;
    if (strncmp(start, "else", length) == 0) return ELSE;
    if (strncmp(start, "switch", length) == 0) return SWITCH;
    if (strncmp(start, "case", length) == 0) return CASE;
    if (strncmp(start, "default", length) == 0) return DEFAULT;
    if (strncmp(start, "for", length) == 0) return FOR;
    if (strncmp(start, "while", length) == 0) return WHILE;
    if (strncmp(start, "do", length) == 0) return DO;
    if (strncmp(start, "class", length) == 0) return CLASS;
    if (strncmp(start, "struct", length) == 0) return STRUCT;
    if (strncmp(start, "public", length) == 0) return PUBLIC;
    if (strncmp(start, "protected", length) == 0) return PROTECTED;
    if (strncmp(start, "private", length) == 0) return PRIVATE;
    if (strncmp(start, "input", length) == 0) return INPUT;
    if (strncmp(start, "#define", length) == 0) return DEFINE;
    if (strncmp(start, "#undef", length) == 0) return UNDEF;
    if (strncmp(start, "int", length) == 0) return INT;
    if (strncmp(start, "string", length) == 0) return STRING;
    if (strncmp(start, "float", length) == 0) return FLOAT;
    if (strncmp(start, "double", length) == 0) return DOUBLE;
    if (strncmp(start, "char", length) == 0) return CHAR;
    if (strncmp(start, "bool", length) == 0) return BOOL;
    if (strncmp(start, "null", length) == 0) return NULL_TOKEN;
    if (strncmp(start, "nullptr", length) == 0) return PTR_NULL;
    return IDENTIFIER;  // Если не найдено - считаем идентификатором
}

// Лексер: анализ строки и вывод токенов
void lexer(const char* input) {
    const char* current = input;

    while (*current != '\0') {
        // Пропуск пробелов и проверка на количество пробелов (считает как табуляции, если кратно 4)
        if (*current == ' ') {
            const char* start = current;
            int space_count = 0;

            while (*current == ' ') {
                space_count++;
                current++;
            }

            // Если количество пробелов кратно 4
            int tab_count = space_count / 4;  // Количество табуляций
            int remaining_spaces = space_count % 4;  // Оставшиеся пробелы

            // Выводим табуляции
            for (int i = 0; i < tab_count; i++) {
                Token token = create_token(tab, "    ", 4);  // Табуляция (4 пробела)
                print_token(token);
            }

            // Выводим оставшиеся пробелы
            for (int i = 0; i < remaining_spaces; i++) {
                Token token = create_token(space, " ", 1);  // Одиночный пробел
                print_token(token);
            }

            continue;
        }

        // Если это "#define" или "#undef"
        if (*current == '#') {
            const char* start = current;
            while (*current != ' ' && *current != '\0') {
                current++;
            }
            TokenType type = check_keyword(start + 1, current - start - 1);
            Token token = create_token(type, start, current - start);
            print_token(token);
            continue;
        }

        // Пропуск табуляции
        if (*current == '\t') {
            Token token = create_token(tab, "\t", 1); // Табуляция
            print_token(token);
            current++;
            continue;
        }

        // Обработка идентификаторов и ключевых слов
        if (isalpha(*current)) {
            const char* start = current;
            while (isalnum(*current) || *current == '_') {
                current++;
            }
            TokenType type = check_keyword(start, current - start);
            Token token = create_token(type, start, current - start);
            print_token(token);
            continue;
        }

        // Обработка чисел
        if (isdigit(*current)) {
            const char* start = current;
            while (isdigit(*current) || *current == '.') {
                current++;
            }
            Token token = create_token(NUMBER, start, current - start);
            print_token(token);
            continue;
        }

        // Обработка операторов (здесь можно добавить больше операторов)
        if (strchr("+-*/=<>!", *current)) {
            const char* start = current;
            current++;
            Token token = create_token(OPERATOR, start, 1);
            print_token(token);
            continue;
        }

        // Пропуск остального
        current++;
    }
}
