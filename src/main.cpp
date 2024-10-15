#include <stdio.h>
#include <stdlib.h>
#include "../headers/stack_func.h"
#include "../headers/compiler.h"
#include "../headers/virt_mach_func.h"

int main()
{
    virt_mach vm;
    VM_Ctor(&vm);
    
    FILE* input = fopen("commands.txt", "r");
    Compiler(input, &vm);
    int i = 0;
    while (vm.code[i] != hlt_c)
    {
        printf("%lld ", vm.code[i++]);
    }
    printf("%lld ", vm.code[i++]);
    return 0;
}