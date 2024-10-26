#ifndef STACK_FUNC_H
#define STACK_FUNC_H

#include "service_stack_func.h"

int StackPush(Stack* stk, stack_t a, FILE* output);

long long StackPop(Stack* stk, FILE* output);

int StackCtor(Stack* stk, FILE* output ON_DEBUG(, const char* name, const char* file, int line));

int StackDtor(Stack* stk, FILE* output);

#endif // STACK_FUNC_H