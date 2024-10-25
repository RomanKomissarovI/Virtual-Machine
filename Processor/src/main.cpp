#include <stdio.h>
#include "../headers/virt_mach_func.h"
#include "../headers/processor.h"

#include "../headers/stack_func.h"

/*  ... СИНХРОНИЗИРОВАТЬ stack_t И command_t
    ... СДЕЛАТЬ КОМАНДЫ ТАКИМИ, ЧТОБЫ МОЖНО БЫЛО ОБОЙТИ SWITCH (ПОНИМАТЬ ПО БИТАМ ЧИТАМУЮ ИНФОРМАЦИЮ)
    ... 3 ПРОГРАММЫ: ASSEMBLER, DISASSEMBLER, PROCESSOR

    push 228228
    jmp next
    push 3
    next:
    pop AX
    hlt
*/

/*
    Not Work:   push 228229
                dump
                push 11
                dump
                hlt
    
    Work:       push 228229
                push 11
                dump
                hlt

*/

int main()
{
    virt_mach vm;
    
    FILE* input = fopen("assembler.txt", "r");
    VM_Ctor(&vm, input);
    
    // int i = 0; 
    // while (vm.code[i] != hlt_c)
    // {
    //     printf(format " ", vm.code[i++]);
    // }
    // printf("0\n");
    
    Run(&vm);
    return 0;
}