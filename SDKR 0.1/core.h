#ifndef CORE_H
#define CORE_H

#include "Vm/ByteCode/ByteCode.h"


#ifdef _WIN32
#include <windows.h>
#endif

void UTF() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
}


#endif // CORE_H
