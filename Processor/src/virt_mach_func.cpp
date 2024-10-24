#include "../headers/virt_mach_func.h"
#include "../headers/stack_func.h"
#include "../headers/macros.h"

void VM_Ctor(virt_mach* vm, FILE* input)
{
    STACK_CTOR(vm->stk);    //stack
    
    int size = 0;
    fscanf(input, "%d", &size);

    vm->code = (command_t*) calloc(size, sizeof(char)); //code
    for(int i = 0; i < (int) (size / sizeof(command_t)); ++i)
    {
        fscanf(input, format, &(vm->code[i]));
    }

    for (int i = 0; i < count_reg; ++i) //registers
    {
        vm->registers[i] = 0;
    }

    // vm->RAM = (command_t*) calloc (RAM_size, sizeof(command_t));
    // for (int i = 0; i < RAM_size; ++i)
    // {
    //     vm->RAM[i] = 0;
    // }
}