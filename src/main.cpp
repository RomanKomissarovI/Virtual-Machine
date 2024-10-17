#include <stdio.h>
#include <stdlib.h>
#include "../headers/stack_func.h"
#include "../headers/compiler.h"
#include "../headers/virt_mach_func.h"
#include "../headers/executor.h"
#include "../headers/stack_func.h"

int main()
{
    virt_mach vm;
    VM_Ctor(&vm);
    
    FILE* input = fopen("commands.txt", "r");
    Compiler(input, &vm);
    int i = 0; 
    while (vm.code[i] != hlt_c)
    {
        printf("%d ", vm.code[i++]);
    }
    printf("\n");
    
    StackDump(&(vm.stk));
    Run(&vm);
    StackDump(&(vm.stk));
    return 0;
}