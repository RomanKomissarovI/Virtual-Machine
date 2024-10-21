#include "../headers/virt_mach_func.h"
#include "../headers/stack_func.h"
#include "../headers/macros.h"

void VM_Ctor(virt_mach* vm)
{
    vm->code = nullptr;
    for (int i = 0; i < count_reg; ++i)
    {
        vm->registers[i] = 0;
    }
    STACK_CTOR(vm->stk);
}