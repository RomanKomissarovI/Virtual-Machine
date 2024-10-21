#include <stdlib.h>
#include <string.h>
#include "../headers/assembler.h"
#include "../headers/virt_mach.h"

// СРАВНЕНИЕ ИЗ ГЛУБИНЫ НАВЕРХ

static const char* str_com[20] = {"hlt",  "push", "pop", "dump", "in",
                           "out",  "add",  "sub", "mul",  "div" ,
                           "sqrt", "sin",  "cos", "jm",   "jme" ,
                           "jl",   "jle",  "je",  "jne",  "jmp"};

void Assembler(FILE* input, long long size)
{
    FILE* output = fopen("../Processor/assembler.txt", "w");
    fprintf(output, "%zu\n", size);

    char com[20];
    command_t d = 0;
    while (true)
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
            fprintf(output, "%d\n", hlt_c);
            return;
        }
        case push_c: {
            fprintf(output, "%d ", push_c);
            fscanf(input, format, &d);
            fprintf(output, format "\n", d);
            break;
        }
        case pop_c: {
            fprintf(output, "%d\n", pop_c);
            break;
        }
        case dump_c: {
            fprintf(output, "%d\n", dump_c);
            break;
        }
        case in_c: {
            fprintf(output, "%d\n", in_c);
            break;
        }
        case out_c: {
            fprintf(output, "%d\n", out_c);
            break;
        }
        case add_c: {
            fprintf(output, "%d\n", add_c);
            break;
        }
        case sub_c: {
            fprintf(output, "%d\n", sub_c);
            break;
        }
        case mul_c: {
            fprintf(output, "%d\n", mul_c);
            break;
        }
        case div_c: {
            fprintf(output, "%d\n", div_c);
            break;
        }
        case sqrt_c: {
            fprintf(output, "%d\n", sqrt_c);
            break;
        }
        case sin_c: {
            fprintf(output, "%d\n", sin_c);
            break;
        }
        case cos_c: {
            fprintf(output, "%d\n", cos_c);
            break;
        }
        case jm_c: {
            fprintf(output, "%d ", jm_c);
            fscanf(input, format, &d);
            fprintf(output, format "\n", d);
            break;
        }
        case jme_c: {
            fprintf(output, "%d ", jme_c);
            fscanf(input, format, &d);
            fprintf(output, format "\n", d);
            break;
        }
        case jl_c: {
            fprintf(output, "%d ", jl_c);
            fscanf(input, format, &d);
            fprintf(output, format "\n", d);
            break;
        }
        case jle_c: {
            fprintf(output, "%d ", jle_c);
            fscanf(input, format, &d);
            fprintf(output, format "\n", d);
            break;
        }
        case je_c: {
            fprintf(output, "%d ", je_c);
            fscanf(input, format, &d);
            fprintf(output, format "\n", d);
            break;
        }
        case jne_c: {
            fprintf(output, "%d ", jne_c);
            fscanf(input, format, &d);
            fprintf(output, format "\n", d);
            break;
        }
        case jmp_c: {
            fprintf(output, "%d ", jmp_c);
            fscanf(input, format, &d);
            fprintf(output, format " \n", d);
            break;
        }
        default:
            fprintf(output, "Error command: %s\n", com);
            break;
        }
    }
}