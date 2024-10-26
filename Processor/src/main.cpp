#include <stdio.h>
#include "../headers/virt_mach_func.h"
#include "../headers/processor.h"

#include "../headers/stack_func.h"

/*  ... СИНХРОНИЗИРОВАТЬ stack_t И command_t
    ... СДЕЛАТЬ КОМАНДЫ ТАКИМИ, ЧТОБЫ МОЖНО БЫЛО ОБОЙТИ SWITCH (ПОНИМАТЬ ПО БИТАМ ЧИТАЕМУЮ ИНФОРМАЦИЮ)
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
/*
    ... ОШИБКА В Vm_Ctor - НЕ РАБОТАЕТ FPRINTF(OUTPUT)
    ... СЧИТКА КОДА ОТДЕЛЬНОЙ ФУНКЦИЕЙ
    ... ДОБАВИТЬ ПРОВЕРКИ
    ... СДЕЛАТЬ БИНАРНЫЙ ФАЙЛ
*/

int main()
{
    virt_mach vm;
    
    FILE* input = fopen("assembler.txt", "r");
    FILE* output = fopen("output.txt", "w");
// perror() я должен почитать
    //fprintf(output, "Elems:\n"); 
    VM_Ctor(&vm, input, output);
    //StackDump(&(vm.stk), output);
    
    // int ip = 0;
    // printf("code:\n%d ", vm.code[ip++]);
    // printf("%d ", vm.code[ip++]);
    // printf("%d ", *(command_t*) (vm.code + ip));
    // ip += sizeof(command_t);
    // printf("%d ", vm.code[ip++]);
    // printf("%d ", vm.code[ip++]);
    // printf("%d ", vm.code[ip++]);
    // printf("%d ", *(command_t*) (vm.code + ip));
    // ip += sizeof(command_t);
    // printf("%d ", vm.code[ip++]);
    // printf("%d ", vm.code[ip++]);
    // // int i = 0; 
    // // while (vm.code[i] != hlt_c)
    // // {
    // //     printf(format " ", vm.code[i++]);
    // // }
    // // printf("0\n");
    
    Run(&vm, output);
    return 0;
}