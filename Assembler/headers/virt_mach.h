#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include "stack.h"
#include "macros.h"

typedef long long command_t;
const int count_reg = 4;
const int count_com = 20;
const int count_labels = 20;

enum CommandCodes {
    hlt_c = 0,
    push_c = 1,
    pop_c = 2,
    dump_c = 3,
    in_c = 4,
    out_c = 5,
    add_c = 6,
    sub_c = 7,
    mul_c = 8,
    div_c = 9,
    sqrt_c = 10,
    sin_c = 11,
    cos_c = 12,
    jm_c = 13,
    jme_c = 14,
    jl_c = 15,
    jle_c = 16,
    je_c = 17,
    jne_c = 18,
    jmp_c = 19,
};

struct virt_mach
{
    Stack stk;
    command_t* code;
    command_t registers[4];
};

#endif // VIRTUAL_MACHINE_H