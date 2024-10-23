#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdio.h>
#include "virt_mach.h"
#include "label.h"

void Assembler(FILE* input, long long size, Label labels[]);

#endif // ASSEMBLER_H