#include <stdlib.h>
#include <string.h>
#include "../headers/compiler.h"
#include "../headers/virt_mach.h"

// СРАВНЕНИЕ ИЗ ГЛУБИНЫ НАВЕРХ

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
        if (strcmp(com, "hlt") == 0)
        {
            vm->code[i++] = hlt_c;
            return;
        }
        else if (strcmp(com, "push") == 0)
        {
            vm->code[i++] = push_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
        }
        else if (strcmp(com, "pop") == 0)
        {
            vm->code[i++] = pop_c;
        }
        else if (strcmp(com, "dump") == 0)
        {
            vm->code[i++] = dump_c;
        }
        else if (strcmp(com, "in") == 0)
        {
            vm->code[i++] = in_c;
        }
        else if (strcmp(com, "out") == 0)
        {
            vm->code[i++] = out_c;
        }
        else if (strcmp(com, "add") == 0)
        {
            vm->code[i++] = add_c;
        }
        else if (strcmp(com, "sub") == 0)
        {
            vm->code[i++] = sub_c;
        }
        else if (strcmp(com, "mul") == 0)
        {
            vm->code[i++] = mul_c;
        }
        else if (strcmp(com, "div") == 0)
        {
            vm->code[i++] = div_c;
        }
        else if (strcmp(com, "sqrt") == 0)
        {
            vm->code[i++] = sqrt_c;
        }
        else if (strcmp(com, "sin") == 0)
        {
            vm->code[i++] = sin_c;
        }
        else if (strcmp(com, "cos") == 0)
        {
            vm->code[i++] = cos_c;
        }
        else if (strcmp(com, "jm") == 0)
        {
            vm->code[i++] = jm_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
        }
        else if (strcmp(com, "jme") == 0)
        {
            vm->code[i++] = jme_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
        }
        else if (strcmp(com, "jl") == 0)
        {
            vm->code[i++] = jl_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
        }
        else if (strcmp(com, "jle") == 0)
        {
            vm->code[i++] = jle_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
        }
        else if (strcmp(com, "je") == 0)
        {
            vm->code[i++] = je_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
        }
        else if (strcmp(com, "jne") == 0)
        {
            vm->code[i++] = jne_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
        }
        else if (strcmp(com, "jmp") == 0)
        {
            vm->code[i++] = jmp_c;
            fscanf(input, format, &d);
            vm->code[i++] = d;
        }
    }
}