#include <stdio.h>
#include <math.h>
#include "../headers/processor.h"
#include "../headers/get_arg.h"

void Run(virt_mach* vm, FILE* output)
{
    int ip = 0;
    while (true)
    {
        printf("  ip: %d, code_ip: %d\n", ip, vm->code[ip]);
        switch (vm->code[ip]) 
        {
            case hlt_c: {
                fclose(output);

                return;
            }
            case push_c: {
                //printf("ABOBA\n");
                ip++;
                StackPush(&(vm->stk), GetArg(vm, &ip), output);

                //printf("PUSH___\n");
                //StackDump(&(vm->stk), output);
                break;
            }
            case pop_c: {
                ip++;

                stack_t elem = StackPop(&(vm->stk), output);
                GetArgPop(vm, &ip, elem);

                break;
            }
            case dump_c: {
                printf("do dump, ip: %d\n", ip);
                StackDump(&(vm->stk), output);
                ip++;
                break;
            }
            case in_c: {
                command_t dig = 0;
                scanf(format, &dig); 
                StackPush(&(vm->stk), dig, output);
                ip++;
                break;
            }
            case out_c: {
                printf(format "\n", StackPop(&(vm->stk), output));
                ip++;
                break;
            }
            case add_c: {
                StackPush(&(vm->stk), StackPop(&(vm->stk), output) + StackPop(&(vm->stk), output), output);
                ip++;
                break;
            }
            case sub_c: {
                command_t x = StackPop(&(vm->stk), output);
                command_t y = StackPop(&(vm->stk), output);
                StackPush(&(vm->stk), y - x, output);
                ip++;
                break;
            }
            case mul_c: {
                StackPush(&(vm->stk), StackPop(&(vm->stk), output) * StackPop(&(vm->stk), output), output);
                ip++;
                break;
            }
            case div_c: {
                command_t divider =  StackPop(&(vm->stk), output);
                StackPush(&(vm->stk), StackPop(&(vm->stk), output) / divider, output);
                ip++;
                break;
            }
            case sqrt_c: {
                StackPush(&(vm->stk), (stack_t) sqrt((double) StackPop(&(vm->stk), output)), output);
                ip++;
                break;
            }
            case sin_c: {
                StackPush(&(vm->stk), (stack_t) sin((double) StackPop(&(vm->stk), output)), output);
                ip++;
                break;
            }
            case cos_c: {
                StackPush(&(vm->stk), (stack_t) cos((double) StackPop(&(vm->stk), output)), output);
                ip++;
                break;
            }
            case jm_c: {
                if (StackPop(&(vm->stk), output) < StackPop(&(vm->stk), output))
                {
                    ip = *(int*) (vm->code + ip + 1);
                    break;
                }
                ip += 2;
                break;
            }
            case jme_c: {
                if (StackPop(&(vm->stk), output) <= StackPop(&(vm->stk), output))
                {
                    ip = *(int*) (vm->code + ip + 1);
                    break;
                }
                ip += 2;
                break;
            }
            case jl_c: {
                if (StackPop(&(vm->stk), output) > StackPop(&(vm->stk), output))
                {
                    ip = *(int*) (vm->code + ip + 1);
                    break;
                }
                ip += 2;
                break;
            }
            case jle_c: {
                if (StackPop(&(vm->stk), output) >= StackPop(&(vm->stk), output))
                {
                    ip = *(int*) (vm->code + ip + 1);
                    break;
                }
                ip += 2;
                break;
            }
            case je_c: {
                if (StackPop(&(vm->stk), output) == StackPop(&(vm->stk), output))
                {
                    ip = *(int*) (vm->code + ip + 1);
                    break;
                }
                ip += 2;
                break;
            }
            case jne_c: {
                if (StackPop(&(vm->stk), output) != StackPop(&(vm->stk), output))
                {
                    ip = *(int*) (vm->code + ip + 1);
                    break;
                }
                ip += 2;
                break;
            }
            case jmp_c: {
                ip = *(int*) (vm->code + ip + 1);
                break;
            }
            default: {
                printf("Error command: %d\n", vm->code[ip]);
                exit(1);
                break;
            }
        }
    }
}