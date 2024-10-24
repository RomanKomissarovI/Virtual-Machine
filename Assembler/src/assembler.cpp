#include <stdlib.h>
#include <string.h>
#include "../headers/assembler.h"
#include "../headers/label_func.h"
#include "../headers/parse_arg.h"

// СРАВНЕНИЕ ИЗ ГЛУБИНЫ НАВЕРХ

static int size = 0;
static const char* str_com[20] = {"hlt",  "push", "pop", "dump", "in",
                                  "out",  "add",  "sub", "mul",  "div",
                                  "sqrt", "sin",  "cos", "jm",   "jme",
                                  "jl",   "jle",  "je",  "jne",  "jmp"};

void Assembler(FILE* input, Label labels[])
{
    FILE* output = fopen("../Processor/assembler.txt", "w"); //fopen("../Processor/assembler.txt", "w");
    FILE* file_labels = fopen("../Processor/labels.txt", "w"); //fopen("../Processor/labels.txt", "w");

    fprintf(output, "%d\n", size);
    if (size != 0) size = 0;

    char com[30];
    int ip = 0;
    char label_name[30];

    while (true)
    {
        fscanf(input, "%s", com);

        if (IsLabel(com))
        {
            InitLabel(labels, com, ip, file_labels);
            continue;
        }
        
        size += sizeof(command_t); // command
        ip += 1; // command

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
            fclose(file_labels);

            return;
        }
        case push_c: {
            fprintf(output, "%d ", push_c);
            
            ParseArgs(input, output, &ip, &size);

            break;
        }
        case pop_c: {
            fprintf(output, "%d ", pop_c);

            ParseArgs(input, output, &ip, &size);

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

            fscanf(input, "%s", label_name);
            fprintf(output, "%d\n", LabelPtr(labels, label_name));

            ip += 1;
            size += sizeof(command_t);

            break;
        }
        case jme_c: {
            fprintf(output, "%d ", jme_c);

            fscanf(input, "%s", label_name);
            fprintf(output, "%d\n", LabelPtr(labels, label_name));
            
            ip += 1;
            size += sizeof(command_t);

            break;
        }
        case jl_c: {
            fprintf(output, "%d ", jl_c);

            fscanf(input, "%s", label_name);
            fprintf(output, "%d\n", LabelPtr(labels, label_name));
            
            ip += 1;
            size += sizeof(command_t);

            break;
        }
        case jle_c: {
            fprintf(output, "%d ", jle_c);

            fscanf(input, "%s", label_name);
            fprintf(output, "%d\n", LabelPtr(labels, label_name));
            
            ip += 1;
            size += sizeof(command_t);

            break;
        }
        case je_c: {
            fprintf(output, "%d ", je_c);

            fscanf(input, "%s", label_name);
            fprintf(output, "%d\n", LabelPtr(labels, label_name));
            
            ip += 1;
            size += sizeof(command_t);

            break;
        }
        case jne_c: {
            fprintf(output, "%d ", jne_c);

            fscanf(input, "%s", label_name);
            fprintf(output, "%d\n", LabelPtr(labels, label_name));
            
            ip += 1;
            size += sizeof(command_t);

            break;
        }
        case jmp_c: {
            fprintf(output, "%d ", jmp_c);

            fscanf(input, "%s", label_name);
            fprintf(output, "%d\n", LabelPtr(labels, label_name));
            
            ip += 1;
            size += sizeof(command_t);

            break;
        }
        default:
            fprintf(output, "Error command: %s\n", com);
            exit(1);
            break;
        }
    }
}
