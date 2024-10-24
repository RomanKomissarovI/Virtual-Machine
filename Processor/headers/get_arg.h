#ifndef GET_ARG_H
#define GET_ARG_H

#include "virt_mach.h"

command_t GetArg(virt_mach* vm, int* ip);

void GetArgPop(virt_mach* vm, int* ip, command_t elem);

#endif // GET_ARG_H