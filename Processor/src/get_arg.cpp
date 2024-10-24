#include "../headers/get_arg.h"

command_t GetArg(virt_mach* vm, int* ip)
{
    int arg_type = (int) vm->code[(*ip)++];
    command_t result = 0;

    if (arg_type & 1) result += vm->registers[vm->code[(*ip)++]];
    if (arg_type & 2) result += vm->code[(*ip)++];
    //if (arg_type & 4) result = vm->RAM[result];

    return result;
}

void GetArgPop(virt_mach* vm, int* ip, command_t elem)
{
    int arg_type = (int) vm->code[(*ip)++];
    command_t* addr = nullptr;
    int index = 0;

    if (arg_type & 1) 
    {
        index = (int) vm->registers[vm->code[(*ip)]];
        addr = &(vm->registers[vm->code[(*ip)++]]);
    }
    if (arg_type & 2) index += (int) vm->code[(*ip)++];
    //if (arg_type & 4) addr = &(vm->RAM[result]);

    if (arg_type & 5) *addr = elem;
}