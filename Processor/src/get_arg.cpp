#include "../headers/get_arg.h"

command_t GetArg(virt_mach* vm, int* ip)
{
    char arg_type = vm->code[(*ip)++];
    command_t result = 0;

    if (arg_type & 1)
    {
         result += vm->registers[(int) vm->code[(*ip)++]];
    }
    if (arg_type & 2)
    {
        result += *(command_t*) (vm->code + (*ip));
        *ip += sizeof(command_t);
    }
    //if (arg_type & 4) result = vm->RAM[result];
    printf("result: %I64d\n", result);
    return result;
}

void GetArgPop(virt_mach* vm, int* ip, command_t elem)
{
    char arg_type = vm->code[(*ip)++];
    command_t* addr = nullptr;
    int index = 0;

    if (arg_type & 1) 
    {
        index = (int) (vm->registers[(int) vm->code[(*ip)]]);
        addr = (command_t*) &(vm->registers[(int) vm->code[((*ip)++)]]);
    }
    if (arg_type & 2)
    {
        index += *(int*) (vm->code + (*ip));
        *ip += sizeof(int); // adr
    } 
    //if (arg_type & 4) addr = &(vm->RAM[result]);

    if (arg_type & 5) *addr = elem;
}