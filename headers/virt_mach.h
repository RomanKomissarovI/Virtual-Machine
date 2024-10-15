#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include "stack.h"

typedef long long command_t;

enum CommandCodes {
    hlt_c = -1,
    push_c = 1,
    pop_c = 2,
    dump_c = 3,
    in_c = 4, // с консоли 
    add_c = 5,
    sub_c = 6,
    mul_c = 7,
    div_c = 8,
    sqrt_c = 9,
    sin_c = 10,
    cos_c = 11,
};

struct virt_mach
{
    Stack stk;
    command_t* code;
};

#endif // VIRTUAL_MACHINE_H