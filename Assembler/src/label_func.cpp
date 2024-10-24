#include <string.h>
#include <stdlib.h>
#include "../headers/assembler_info.h"
#include "../headers/label_func.h"

bool IsLabel(char* label_name)
{
    return (strlen(label_name) >= 2) && (label_name[strlen(label_name) - 1] == ':');
}

void InitLabel(Label labels[], char* label_name, int ip, FILE* file_labels)
{
    int i = 0;
    label_name[strlen(label_name) - 1] = '\0';

    while ((i < count_labels) && (labels[i].ip != -1) && (strcmp(labels[i].name, label_name) != 0)) i++;

    labels[i].ip = ip;

    labels[i].name = (char*) calloc (strlen(label_name) + 1, sizeof(char));
    strcpy(labels[i].name, label_name);

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