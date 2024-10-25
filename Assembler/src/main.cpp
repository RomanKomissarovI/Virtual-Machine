#include "../headers/assembler.h"

/*
    ... СДЕЛАТЬ КОМАНДЫ ТАКИМИ, ЧТОБЫ МОЖНО БЫЛО ОБОЙТИ SWITCH (ПОНИМАТЬ ПО БИТАМ ЧИТАМУЮ ИНФОРМАЦИЮ)
*/

int main()
{
    FILE* input = fopen("commands.txt", "r");

    Label labels[20];
    for(int i = 0; i < count_labels; ++i)
    {
        labels[i].ip = -1;
        labels[i].name = "";
    }

    Assembler(input, labels);
    
    fclose(input);
    input = fopen("commands.txt", "r");

    Assembler(input, labels);

    fclose(input);

    for(int i = 0; i < count_labels; ++i)
    {
        printf("ip: %d, ", labels[i].ip);
        printf("name: %s\n", labels[i].name);
    }
    return 0;
}