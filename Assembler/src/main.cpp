#include "../headers/assembler.h"
#include "../headers/size_counter.h"
#include "../headers/label_func.h"

int main()
{
    FILE* input = fopen("commands.txt", "r");
    int size = SizeCounter(input);
    
    fclose(input);
    input = fopen("commands.txt", "r");

    Label labels[20];
    for(int i = 0; i < count_labels; ++i)
    {
        labels[i].ip = -1;
        labels[i].name = "";
    }

    InitAllLabels(input, labels);

    fclose(input);
    input = fopen("commands.txt", "r");

    Assembler(input, size, labels);

    fclose(input);

    for(int i = 0; i < count_labels; ++i)
    {
        printf("ip: %d, ", labels[i].ip);
        printf("name: %s\n", labels[i].name);
    }
    return 0;
}