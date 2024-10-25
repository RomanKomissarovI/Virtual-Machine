#include "../headers/virt_mach_func.h"
#include "../headers/stack_func.h"
#include "../headers/macros.h"

void VM_Ctor(virt_mach* vm, FILE* input)
{
    STACK_CTOR(vm->stk);    //stack
    
    int size = 0;
    fscanf(input, "%d", &size);

    vm->code = (char*) calloc(size, sizeof(char)); //code
    int ip = 0;
    int arg_type = 0;
    while (ip < size)
    {
        fscanf(input, "%d ", &(vm->code[ip]));
        printf("%d ", vm->code[ip]);
        if (vm->code[ip] == push_c){
            fscanf(input, "%d", &(vm->code[++ip]));
            printf("%d ", vm->code[ip]);
            arg_type = vm->code[ip++];
            if (arg_type & 1) {
                fscanf(input, "%d", &(vm->code[ip++]));
                printf("%d ", vm->code[ip - 1]);
            }
            if (arg_type & 2)
            {
                fscanf(input, format, (command_t*) (vm->code + ip));
                printf(format " ", *(command_t*) (vm->code + ip));
                ip += sizeof(command_t);
            }
        }
        else if (vm->code[ip] == pop_c){
            fscanf(input, "%d", &(vm->code[++ip]));
            printf("%d ", vm->code[ip]);
            arg_type = vm->code[ip++];
            if (arg_type & 1) 
            {
                fscanf(input, "%d", &(vm->code[ip++]));
                printf("%d ", vm->code[ip - 1]);
            }
            if (arg_type & 2)
            {
                fscanf(input, "%d", (int*) (vm->code + ip)); // adr
                printf("%d", *(int*) (vm->code + ip));
                ip += sizeof(int);              // adr
            }
        }
        else if ((vm->code[ip] >= jm_c) && (vm->code[ip] <= jmp_c))
        {
            fscanf(input, "%d", (int*) (vm->code + ip + 1));  // adr
            printf("%d ", *(int*) (vm->code + ip + 1));
            ip += sizeof(int) + 1;          // adr
        }
        else ip++;
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