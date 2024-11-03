#ifndef COREGM_H
#define COREGM_H

#include "parser/lexer/lexer.h"
#include "parser/parser.h"
#include "Generator/code_generator.h"
#include "Generator/bytecode.h"

#ifdef _WIN32
#include <windows.h>
#endif

void UTF() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
}

#endif // COREGM_H
