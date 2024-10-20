#include <stdio.h>
#include <math.h>
#include "../headers/executor.h"

void Run(virt_mach* vm)
{
    size_t ip = 0;
    while (true)
    {
        switch (vm->code[ip]) 
        {
            case -1: {
                return;
            }
            case 1: {
                StackPush(&(vm->stk), vm->code[ip + 1]);
                ip += 2;
                break;
            }
            case 2: {
                StackPop(&(vm->stk));
                ip++;
                break;
            }
            case 3: {
                StackDump(&(vm->stk));
                ip++;
                break;
            }
            case 4: {
                command_t dig = 0;
                scanf(format, &dig); // const format
                StackPush(&(vm->stk), dig);
                ip++;
                break;
            }
            case 5: {
                printf(format "\n", *(stack_t*) (vm->stk.data + (vm->stk.size - 1) * sizeof(stack_t)));
                ip++;
                break;
            }
            case 6: {
                StackPush(&(vm->stk), StackPop(&(vm->stk)) + StackPop(&(vm->stk)));
                ip++;
                break;
            }
            case 7: {
                StackPush(&(vm->stk), -StackPop(&(vm->stk)) + StackPop(&(vm->stk)));
                ip++;
                break;
            }
            case 8: {
                StackPush(&(vm->stk), StackPop(&(vm->stk)) * StackPop(&(vm->stk)));
                ip++;
                break;
            }
            case 9: {
                command_t divider =  StackPop(&(vm->stk));
                StackPush(&(vm->stk), StackPop(&(vm->stk)) / divider);
                ip++;
                break;
            }
            case 10: {
                StackPush(&(vm->stk), (stack_t) sqrt((double) StackPop(&(vm->stk))));
                ip++;
                break;
            }
            case 11: {
                StackPush(&(vm->stk), (stack_t) sin((double) StackPop(&(vm->stk))));
                ip++;
                break;
            }
            case 12: {
                StackPush(&(vm->stk), (stack_t) cos((double) StackPop(&(vm->stk))));
                ip++;
                break;
            }
            case 13: {
                if (StackPop(&(vm->stk)) < StackPop(&(vm->stk)))
                {
                    ip = (size_t) vm->code[ip + 1];
                    break;
                }
                ip += 2;
                break;
            }
            case 14: {
                if (StackPop(&(vm->stk)) <= StackPop(&(vm->stk)))
                {
                    ip = (size_t) vm->code[ip + 1];
                    break;
                }
                ip += 2;
                break;
            }
            case 15: {
                if (StackPop(&(vm->stk)) > StackPop(&(vm->stk)))
                {
                    ip = (size_t) vm->code[ip + 1];
                    break;
                }
                ip += 2;
                break;
            }
            case 16: {
                if (StackPop(&(vm->stk)) >= StackPop(&(vm->stk)))
                {
                    ip = (size_t) vm->code[ip + 1];
                    break;
                }
                ip += 2;
                break;
            }
            case 17: {
                if (StackPop(&(vm->stk)) == StackPop(&(vm->stk)))
                {
                    ip = (size_t) vm->code[ip + 1];
                    break;
                }
                ip += 2;
                break;
            }
            case 18: {
                if (StackPop(&(vm->stk)) != StackPop(&(vm->stk)))
                {
                    ip = (size_t) vm->code[ip + 1];
                    break;
                }
                ip += 2;
                break;
            }
            case 19: {
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