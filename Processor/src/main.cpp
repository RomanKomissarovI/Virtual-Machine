#include <stdio.h>
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
    
    FILE* input = fopen("assembler.txt", "r");
    VM_Ctor(&vm, input);
    
    int i = 0; 
    while (vm.code[i] != hlt_c)
    {
        printf(format " ", vm.code[i++]);
    }
    printf("0\n");
    
    Run(&vm);
    return 0;
}