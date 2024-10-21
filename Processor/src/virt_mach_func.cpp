#include "../headers/virt_mach_func.h"
#include "../headers/stack_func.h"
#include "../headers/macros.h"

void VM_Ctor(virt_mach* vm, FILE* input)
{
    size_t size = 0;
    fscanf(input, "%zu", &size);
    vm->code = (command_t*) calloc(size, sizeof(char));
    for(int i = 0; i < (int) (size / sizeof(command_t)); ++i)
    {
        fscanf(input, format, &(vm->code[i]));
    }
    for (int i = 0; i < count_reg; ++i)
    {
        vm->registers[i] = 0;
    }

    STACK_CTOR(vm->stk);
}