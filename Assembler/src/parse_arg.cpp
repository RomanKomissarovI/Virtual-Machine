#include <stdlib.h>
#include <ctype.h>
#include "../headers/parse_arg.h"

static const int Max_len_args = 50;
// сделать различие AX + 12; AX * 12; AX - 12
void ParseArgs(FILE* input, FILE* output, int* ip, int* size)
{
    int reg = -1;
    command_t digit = 0;
    char info_byte = 0;
    char bracket_open = 0, bracket_closed = 0;

    char all_args[50];
    fgets(all_args, Max_len_args - 1, input);

    int i = 0;
    while (all_args[i] != '\0')
    {
        switch (all_args[i])
        {
        case '[':
            bracket_open = 1;
            info_byte |= 4;
            break;
        case 'X':
            info_byte |= 1;
            reg = all_args[i - 1] - 'A';
            break;
        case ']':
            bracket_closed = 1;
            break;
        default:{
            if (! isdigit(all_args[i])) break;

            info_byte |= 2;
            digit = atoi(all_args + i);

            while (isdigit(all_args[++i])) ;
            continue;
        }
        }
        ++i;
    }

    if (bracket_open != bracket_closed)
    {
        printf("Error: ip: %d, args: %sBracket was not closed\n", *ip, all_args);
        exit(1);
    }

    fprintf(output, "%d ", info_byte);
    (*ip)++;
    (*size) += sizeof(command_t);

    if (info_byte & 1)
    {
        fprintf(output, "%d ", reg);
        (*ip)++;
        (*size) += sizeof(command_t);
    }
    if (info_byte & 2)
    {
        fprintf(output, format_code, digit);
        (*ip)++;
        (*size) += sizeof(command_t);
    }
    fprintf(output, "\n");
}