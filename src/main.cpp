#include <stdio.h>
#include <stdlib.h>
#include "../headers/stack_func.h"
#include "../headers/assembler.h"
#include "../headers/virt_mach_func.h"
#include "../headers/processor.h"
#include "../headers/stack_func.h"

/* ... 3 ПРОГРАММЫ: ASSEMBLER, DISASSEMBLER, PROCESSOR
   ... NAMING: COMPILER -> ASSEMBLER; EXECUTOR -> PROCESSOR
   ... ИЗБАВИТЬСЯ ОТ ELSE IF В COMPILER: СДЕЛАТЬ МАССИВ СТРУКТУР ЧИСЛО-СТРОКА (НОМЕР_КОМАНДЫ - СТРОКОВОЕ ПРЕДСТВАЛЕНИЕ). FOR-ОМ НАЙТИ НУЖНЫЙ КОД
   И СДЕЛАТЬ SWITCH ВМЕСТО ELSE-IF*/

int main()
{
    virt_mach vm;
    VM_Ctor(&vm);
    
    FILE* input = fopen("commands.txt", "r");
    Compiler(input, &vm);
    fclose(input);
    int i = 0; 
    while (vm.code[i] != hlt_c)
    {
        printf(format " ", vm.code[i++]);
    }
    printf("-1\n");
    

    //StackDump(&(vm.stk));
    Run(&vm);
    //StackDump(&(vm.stk));
    return 0;
}