#ifndef PARSE_ARG_H
#define PARSE_ARG_H

#include <stdio.h>
#include "assembler_info.h"
#include "../headers/assembler_info.h"

void ParseArgs(FILE* input, FILE* output, int* ip, int* size);

#endif // PARSE_ARG_H