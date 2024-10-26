#include "compiler.h"

Node *parse(Token *tokens) {
    Node *ast = (Node *)malloc(sizeof(Node));
    ast->type = "root";
    return ast;
}
