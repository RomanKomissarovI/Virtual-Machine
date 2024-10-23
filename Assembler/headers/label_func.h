#ifndef LABEL_FUNC_H
#define LABEL_FUNC_H

#include <stdio.h>
#include "label.h"

void InitAllLabels(FILE* input, Label labels[]);

bool IsLabel(char* str);

void InitLabel(Label labels[], char* com, int ip, FILE* file_labels);

int LabelPtr(Label labels[], char* label_name);

#endif // LABEL_FUNC_H