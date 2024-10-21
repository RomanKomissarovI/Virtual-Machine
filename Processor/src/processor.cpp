#include <stdio.h>
#include <math.h>
#include "../headers/processor.h"

void Run(virt_mach* vm)
{
    size_t ip = 0;
    while (true)
    {
        switch (vm->code[ip]) 
        {
            case hlt_c: {
                return;
            }
            case push_c: {
                StackPush(&(vm->stk), vm->code[ip + 1]);
                ip += 2;
                break;
            }
            case pop_c: {
                StackPop(&(vm->stk));
                ip++;
                break;
            }
            case dump_c: {
                StackDump(&(vm->stk));
                ip++;
                break;
            }
            case in_c: {
                command_t dig = 0;
                scanf(format, &dig); // const format
                StackPush(&(vm->stk), dig);
                ip++;
                break;
            }
            case out_c: {
                printf(format "\n", StackPop(&(vm->stk)));
                ip++;
                break;
            }
            case add_c: {
                StackPush(&(vm->stk), StackPop(&(vm->stk)) + StackPop(&(vm->stk)));
                ip++;
                break;
            }
            case sub_c: {
                command_t x = StackPop(&(vm->stk));
                command_t y = StackPop(&(vm->stk));
                StackPush(&(vm->stk), y - x);
                ip++;
                break;
            }
            case mul_c: {
                StackPush(&(vm->stk), StackPop(&(vm->stk)) * StackPop(&(vm->stk)));
                ip++;
                break;
            }
            case div_c: {
                command_t divider =  StackPop(&(vm->stk));
                StackPush(&(vm->stk), StackPop(&(vm->stk)) / divider);
                ip++;
                break;
            }
            case sqrt_c: {
                StackPush(&(vm->stk), (stack_t) sqrt((double) StackPop(&(vm->stk))));
                ip++;
                break;
            }
            case sin_c: {
                StackPush(&(vm->stk), (stack_t) sin((double) StackPop(&(vm->stk))));
                ip++;
                break;
            }
            case cos_c: {
                StackPush(&(vm->stk), (stack_t) cos((double) StackPop(&(vm->stk))));
                ip++;
                break;
            }
            case jm_c: {
                if (StackPop(&(vm->stk)) < StackPop(&(vm->stk)))
                {
                    ip = (size_t) vm->code[ip + 1];
                    break;
                }
                ip += 2;
                break;
            }
            case jme_c: {
                if (StackPop(&(vm->stk)) <= StackPop(&(vm->stk)))
                {
                    ip = (size_t) vm->code[ip + 1];
                    break;
                }
                ip += 2;
                break;
            }
            case jl_c: {
                if (StackPop(&(vm->stk)) > StackPop(&(vm->stk)))
                {
                    ip = (size_t) vm->code[ip + 1];
                    break;
                }
                ip += 2;
                break;
            }
            case jle_c: {
                if (StackPop(&(vm->stk)) >= StackPop(&(vm->stk)))
                {
                    ip = (size_t) vm->code[ip + 1];
                    break;
                }
                ip += 2;
                break;
            }
            case je_c: {
                if (StackPop(&(vm->stk)) == StackPop(&(vm->stk)))
                {
                    ip = (size_t) vm->code[ip + 1];
                    break;
                }
                ip += 2;
                break;
            }
            case jne_c: {
                if (StackPop(&(vm->stk)) != StackPop(&(vm->stk)))
                {
                    ip = (size_t) vm->code[ip + 1];
                    break;
                }
                ip += 2;
                break;
            }
            case jmp_c: {
                ip = (size_t) vm->code[ip + 1];
                break;
            }
            default: {
                printf("Error command\n");
                exit(1);
                break;
            }
        }
    }
}