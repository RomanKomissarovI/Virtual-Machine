#include <string.h>
#include <stdlib.h>
#include "../headers/assembler_info.h"
#include "../headers/label_func.h"

static const char* str_com[20] = {"hlt",  "push", "pop", "dump", "in",
                           "out",  "add",  "sub", "mul",  "div" ,
                           "sqrt", "sin",  "cos", "jm",   "jme" ,
                           "jl",   "jle",  "je",  "jne",  "jmp"};

void InitAllLabels(FILE* input, Label labels[])
{
    FILE* file_labels = fopen("../Processor/labels.txt", "w"); //fopen("../Processor/labels.txt", "w");

    char com[20];
    int ip = 0;
    command_t d = 0;
    char label_name[30];

    while (true)
    {
        fscanf(input, "%s", com);

        if (IsLabel(com))
        {
            InitLabel(labels, com, ip, file_labels);
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
            fclose(file_labels);

            return;
        }
        case push_c: {
            ip += 1;
            fscanf(input, format_code, &d);
            ip += 1;
            break;
        }
        case pop_c: {
            ip += 1;
            break;
        }
        case dump_c: {
            ip += 1;
            break;
        }
        case in_c: {
            ip += 1;
            break;
        }
        case out_c: {
            ip += 1;
            break;
        }
        case add_c: {
            ip += 1;
            break;
        }
        case sub_c: {
            ip += 1;
            break;
        }
        case mul_c: {
            ip += 1;
            break;
        }
        case div_c: {
            ip += 1;
            break;
        }
        case sqrt_c: {
            ip += 1;
            break;
        }
        case sin_c: {
            ip += 1;
            break;
        }
        case cos_c: {
            ip += 1;
            break;
        }
        case jm_c: {
            ip += 1;
            fscanf(input, "%s", label_name);
            ip += 1;
            break;
        }
        case jme_c: {
            ip += 1;
            fscanf(input, "%s", label_name);
            ip += 1;
            break;
        }
        case jl_c: {
            ip += 1;
            fscanf(input, "%s", label_name);
            ip += 1;
            break;
        }
        case jle_c: {
            ip += 1;
            fscanf(input, "%s", label_name);
            ip += 1;
            break;
        }
        case je_c: {
            ip += 1;
            fscanf(input, "%s", label_name);
            ip += 1;
            break;
        }
        case jne_c: {
            ip += 1;
            fscanf(input, "%s", label_name);
            ip += 1;
            break;
        }
        case jmp_c: {
            ip += 1;
            fscanf(input, "%s", label_name);
            ip += 1;
            break;
        }
        default:
            break;
        }
    }
}

bool IsLabel(char* com)
{
    return (strlen(com) >= 2) && (com[strlen(com) - 1] == ':');
}

void InitLabel(Label labels[], char* com, int ip, FILE* file_labels)
{
    int i = 0;
    while ((i < count_labels) && (labels[i].ip != -1)) i++;

    labels[i].ip = ip;

    com[strlen(com) - 1] = '\0';
    labels[i].name = (char*) calloc (strlen(com) + 1, sizeof(char));
    strcpy(labels[i].name, com);

    fprintf(file_labels, "%s %d\n", labels[i].name, labels[i].ip);
}

int LabelPtr(Label labels[], char* label_name)
{
    for (int i = 0; i < count_labels; ++i)
    {
        if (strcmp(labels[i].name, label_name) == 0)
        {
            return labels[i].ip;
        }
    }
    return -1;
}