#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include "stack.h"
#include "macros.h"

typedef long long command_t;

enum CommandCodes {
    hlt_c = -1,
    push_c = 1,
    pop_c = 2,
    dump_c = 3,
    in_c = 4, // с консоли 
    out_c = 5,
    add_c = 6,
    sub_c = 7,
    mul_c = 8,
    div_c = 9,
    sqrt_c = 10,
    sin_c = 11,
    cos_c = 12,
};

struct virt_mach
{
    Stack stk;
    command_t* code;
};

#endif // VIRTUAL_MACHINE_H