#include "../headers/virt_mach_func.h"
#include "../headers/stack_func.h"
#include "../headers/macros.h"

void VM_Ctor(virt_mach* vm)
{
    vm->code = nullptr;
    STACK_CTOR(vm->stk);
}