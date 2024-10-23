#include <stdlib.h>
#include <string.h>
#include "../headers/assembler.h"
#include "../headers/virt_mach.h"
#include "../headers/label_func.h"

// СРАВНЕНИЕ ИЗ ГЛУБИНЫ НАВЕРХ
// LABEL: "__NAME__\0__DIGIT__\0"

static const char* str_com[20] = {"hlt",  "push", "pop", "dump", "in",
                           "out",  "add",  "sub", "mul",  "div" ,
                           "sqrt", "sin",  "cos", "jm",   "jme" ,
                           "jl",   "jle",  "je",  "jne",  "jmp"};

void Assembler(FILE* input, long long size, Label labels[])
{
    FILE* output = fopen("../Processor/assembler.txt", "w");
    fprintf(output, "%zu\n", size);

    char com[30];
    int ip = 0;
    command_t d = 0;
    char label_name[30];
    while (true)
    {
        fscanf(input, "%s", com);

        if (IsLabel(com))
        {
            continue;
        }

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

            fclose(output);

            return;
        }
        case push_c: {
            fprintf(output, "%d ", push_c);
            ip += 1;
            fscanf(input, format, &d);
            fprintf(output, format "\n", d);
            ip += 1;
            break;
        }
        case pop_c: {
            fprintf(output, "%d\n", pop_c);
            ip += 1;
            break;
        }
        case dump_c: {
            fprintf(output, "%d\n", dump_c);
            ip += 1;
            break;
        }
        case in_c: {
            fprintf(output, "%d\n", in_c);
            ip += 1;
            break;
        }
        case out_c: {
            fprintf(output, "%d\n", out_c);
            ip += 1;
            break;
        }
        case add_c: {
            fprintf(output, "%d\n", add_c);
            ip += 1;
            break;
        }
        case sub_c: {
            fprintf(output, "%d\n", sub_c);
            ip += 1;
            break;
        }
        case mul_c: {
            fprintf(output, "%d\n", mul_c);
            ip += 1;
            break;
        }
        case div_c: {
            fprintf(output, "%d\n", div_c);
            ip += 1;
            break;
        }
        case sqrt_c: {
            fprintf(output, "%d\n", sqrt_c);
            ip += 1;
            break;
        }
        case sin_c: {
            fprintf(output, "%d\n", sin_c);
            ip += 1;
            break;
        }
        case cos_c: {
            fprintf(output, "%d\n", cos_c);
            ip += 1;
            break;
        }
        case jm_c: {
            fprintf(output, "%d ", jm_c);
            ip += 1;
            fscanf(input, "%s", label_name);
            fprintf(output, "%d\n", LabelPtr(labels, label_name));
            ip += 1;
            break;
        }
        case jme_c: {
            fprintf(output, "%d ", jme_c);
            ip += 1;
            fscanf(input, "%s", label_name);
            fprintf(output, "%d\n", LabelPtr(labels, label_name));
            ip += 1;
            break;
        }
        case jl_c: {
            fprintf(output, "%d ", jl_c);
            ip += 1;
            fscanf(input, "%s", label_name);
            fprintf(output, "%d\n", LabelPtr(labels, label_name));
            ip += 1;
            break;
        }
        case jle_c: {
            fprintf(output, "%d ", jle_c);
            ip += 1;
            fscanf(input, "%s", label_name);
            fprintf(output, "%d\n", LabelPtr(labels, label_name));
            ip += 1;
            break;
        }
        case je_c: {
            fprintf(output, "%d ", je_c);
            ip += 1;
            fscanf(input, "%s", label_name);
            fprintf(output, "%d\n", LabelPtr(labels, label_name));
            ip += 1;
            break;
        }
        case jne_c: {
            fprintf(output, "%d ", jne_c);
            ip += 1;
            fscanf(input, "%s", label_name);
            fprintf(output, "%d\n", LabelPtr(labels, label_name));
            ip += 1;
            break;
        }
        case jmp_c: {
            fprintf(output, "%d ", jmp_c);
            ip += 1;
            fscanf(input, "%s", label_name);
            fprintf(output, "%d\n", LabelPtr(labels, label_name));
            ip += 1;
            break;
        }
        default:
            fprintf(output, "Error command: %s\n", com);
            break;
        }
    }
}
