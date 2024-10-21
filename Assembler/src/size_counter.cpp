#include <string.h>
#include "../headers/virt_mach.h"
#include "../headers/size_counter.h"

static const char* str_com[20] = {"hlt",  "push", "pop", "dump", "in",
                           "out",  "add",  "sub", "mul",  "div" ,
                           "sqrt", "sin",  "cos", "jm",   "jme" ,
                           "jl",   "jle",  "je",  "jne",  "jmp"};

long long SizeCounter(FILE* input)
{
    long long size = 0;
    char com[20];
    command_t d = 0;

    while (true)
    {
        fscanf(input, "%s", com);
        size += sizeof(command_t);

        int int_command = -10;
        for (int iter = 0; iter < count_com; ++iter)
        {
            if (strcmp(com, str_com[iter]) == 0)
            {
                int_command = iter;
                break;
            }
        }

        switch (int_command)
        {
        case hlt_c: {
            return size;
        }
        case push_c: {
            size += sizeof(command_t);
            break;
        }
        case pop_c: {
            break;
        }
        case dump_c: {
            break;
        }
        case in_c: {
            break;
        }
        case out_c: {
            break;
        }
        case add_c: {
            break;
        }
        case sub_c: {
            break;
        }
        case mul_c: {
            break;
        }
        case div_c: {
            break;
        }
        case sqrt_c: {
            break;
        }
        case sin_c: {
            break;
        }
        case cos_c: {
            break;
        }
        case jm_c: {
            size += sizeof(command_t);
            break;
        }
        case jme_c: {
            size += sizeof(command_t);
            break;
        }
        case jl_c: {
            size += sizeof(command_t);
            break;
        }
        case jle_c: {
            size += sizeof(command_t);
            break;
        }
        case je_c: {
            size += sizeof(command_t);
            break;
        }
        case jne_c: {
            size += sizeof(command_t);
            break;
        }
        case jmp_c: {
            size += sizeof(command_t);
            break;
        }
        default:
            break;
        }
    }
}