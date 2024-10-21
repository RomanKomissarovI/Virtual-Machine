#include "../headers/assembler.h"
#include "../headers/size_counter.h"

int main()
{
    FILE* input = fopen("commands.txt", "r");
    long long size = SizeCounter(input);

    fclose(input);
    input = fopen("commands.txt", "r");

    Assembler(input, size);
    fclose(input);
    return 0;
}