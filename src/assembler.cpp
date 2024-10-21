#include <stdlib.h>
#include <string.h>
#include "../headers/assembler.h"
#include "../headers/virt_mach.h"

// СРАВНЕНИЕ ИЗ ГЛУБИНЫ НАВЕРХ

const char* str_com[20] = {"hlt",  "push", "pop", "dump", "in",
                           "out",  "add",  "sub", "mul",  "div" ,
                           "sqrt", "sin",  "cos", "jm",   "jme" ,
                           "jl",   "jle",  "je",  "jne",  "jmp"};

void Compiler(FILE* input, virt_mach* vm)
{
    size_t size = 0;
    fscanf(input, "%zu", &size);
    vm->code = (command_t*) calloc (size, sizeof(command_t));
    
    char com[20];
    command_t d = 0;
    size_t i = 0;
    while (i < size)
    {
        fscanf(input, "%s", com);

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
            vm->code[i++] = hlt_c;
            return;
        }
        case push_c: {
            vm->code[i++] = push_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
            break;
        }
        case pop_c: {
            vm->code[i++] = pop_c;
            break;
        }
        case dump_c: {
            vm->code[i++] = dump_c;
            break;
        }
        case in_c: {
            vm->code[i++] = in_c;
            break;
        }
        case out_c: {
            vm->code[i++] = out_c;
            break;
        }
        case add_c: {
            vm->code[i++] = add_c;
            break;
        }
        case sub_c: {
            vm->code[i++] = sub_c;
            break;
        }
        case mul_c: {
            vm->code[i++] = mul_c;
            break;
        }
        case div_c: {
            vm->code[i++] = div_c;
            break;
        }
        case sqrt_c: {
            vm->code[i++] = sqrt_c;
            break;
        }
        case sin_c: {
            vm->code[i++] = sin_c;
            break;
        }
        case cos_c: {
            vm->code[i++] = cos_c;
            break;
        }
        case jm_c: {
            vm->code[i++] = jm_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
            break;
        }
        case jme_c: {
            vm->code[i++] = jme_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
            break;
        }
        case jl_c: {
            vm->code[i++] = jl_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
            break;
        }
        case jle_c: {
            vm->code[i++] = jle_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
            break;
        }
        case je_c: {
            vm->code[i++] = je_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
            break;
        }
        case jne_c: {
            vm->code[i++] = jne_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
            break;
        }
        case jmp_c: {
            vm->code[i++] = jmp_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
            break;
        }
        default:
            printf("Error command: %s\n", com);
            break;
        }
    }
}