#include <stdio.h>
#include "lexer.h"

// Функция для вывода токена
void print_token(Token token) {
    switch (token.type) {
        case space:
            printf("Space: %s\n", token.value);
            break;
        case tab:
            printf("Tab: %s\n", token.value);
            break;
        case NUMBER:
            printf("Number: %s\n", token.value);
            break;
        case IDENTIFIER:
            printf("Identifier: %s\n", token.value);
            break;
        case OPERATOR:
            printf("Operator: %s\n", token.value);
            break;
        case IMPORT:
            printf("Import: %s\n", token.value);
            break;
        case VOID:
            printf("Void: %s\n", token.value);
            break;
        case MAIN:
            printf("Main: %s\n", token.value);
            break;
        case RETURN:
            printf("Return: %s\n", token.value);
            break;
        case IF:
            printf("If: %s\n", token.value);
            break;
        case ELIF:
            printf("Elif: %s\n", token.value);
            break;
        case ELSE:
            printf("Else: %s\n", token.value);
            break;
        case SWITCH:
            printf("Switch: %s\n", token.value);
            break;
        case CASE:
            printf("Case: %s\n", token.value);
            break;
        case DEFAULT:
            printf("Default: %s\n", token.value);
            break;
        case FOR:
            printf("For: %s\n", token.value);
            break;
        case WHILE:
            printf("While: %s\n", token.value);
            break;
        case DO:
            printf("Do: %s\n", token.value);
            break;
        case CLASS:
            printf("Class: %s\n", token.value);
            break;
        case STRUCT:
            printf("Struct: %s\n", token.value);
            break;
        case PUBLIC:
            printf("Public: %s\n", token.value);
            break;
        case PROTECTED:
            printf("Protected: %s\n", token.value);
            break;
        case PRIVATE:
            printf("Private: %s\n", token.value);
            break;
        case INPUT:
            printf("Input: %s\n", token.value);
            break;
        case DEFINE:
            printf("Define: %s\n", token.value);
            break;
        case UNDEF:
            printf("Undef: %s\n", token.value);
            break;
        case INT:
            printf("Int: %s\n", token.value);
            break;
        case STRING:
            printf("String: %s\n", token.value);
            break;
        case FLOAT:
            printf("Float: %s\n", token.value);
            break;
        case DOUBLE:
            printf("Double: %s\n", token.value);
            break;
        case CHAR:
            printf("Char: %s\n", token.value);
            break;
        case BOOL:
            printf("Bool: %s\n", token.value);
            break;
        case NULL_TOKEN:
            printf("Null: %s\n", token.value);
            break;
        case PTR_NULL:
            printf("Pointer Null: %s\n", token.value);
            break;
        case UNKNOWN:
            printf("Unknown: %s\n", token.value);
            break;
        default:
            printf("Unknown token type: %s\n", token.value);
            break;
    }
}
