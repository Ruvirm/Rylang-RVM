#ifndef COMPILER_H
#define COMPILER_H

typedef struct {
    char *type;
    char *value;
} Token;

typedef struct Node {
    char *type;
    struct Node *left;
    struct Node *right;
} Node;

Token *lex(const char *source);
Node *parse(Token *tokens);
int *generate_bytecode(Node *ast);

#endif
