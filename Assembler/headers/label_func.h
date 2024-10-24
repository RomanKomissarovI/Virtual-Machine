#ifndef LABEL_FUNC_H
#define LABEL_FUNC_H

#include <stdio.h>
#include "label.h"

bool IsLabel(char* label_name);

void InitLabel(Label labels[], char* label_name, int ip, FILE* file_labels);

int LabelPtr(Label labels[], char* label_name);

#endif // LABEL_FUNC_H