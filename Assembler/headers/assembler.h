#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdio.h>
#include "assembler_info.h"
#include "label.h"

void Assembler(FILE* input, Label labels[]);

#endif // ASSEMBLER_H