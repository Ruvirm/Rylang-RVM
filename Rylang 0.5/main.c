#include <stdio.h>
#include "lexer.h"

int main() {
    const char* input = "import mylib\n"
                        "int main() {\n"
                        "    return 0;\n"
                        "}\n";
    lexer(input);
    return 0;
}
