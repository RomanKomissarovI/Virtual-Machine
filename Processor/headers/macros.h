#ifndef MACROS_H
#define MACROS_H

#include <stdlib.h>

//#define DEBUG
#define format "%I64d"

#ifdef DEBUG
    #define DEBUG_PRINTF(...) printf(__VA_ARGS__)
    #define DEBUG_PR_ERR(err, output) {                                         \
        if (err != 0) {                                                 \
            PrintError(err, __FILE__, __LINE__, __PRETTY_FUNCTION__, output);   \
            return err;                                                 \
        }                                                               \
    }
    #define ON_DEBUG(...) __VA_ARGS__

    #define STACK_CTOR(stk, output) StackCtor(&stk, output, #stk, __FILE__, __LINE__)
    #define STACK_DUMP(stk, output) StackDump(stk, output, __FILE__, __LINE__)
#else
    #define DEBUG_PRINTF(...)
    #define DEBUG_PR_ERR(err, output) {                                         \
        if (err != 0) {                                                 \
            PrintError(err, __FILE__, __LINE__, __PRETTY_FUNCTION__, output);   \
            return err;                                                 \
        }                                                               \
    }
    #define ON_DEBUG(...)

    #define STACK_CTOR(stk, output) StackCtor(&stk, output)
    #define STACK_DUMP(stk, output) StackDump(stk, output)
#endif

#define Free(ptr) \
{                 \
    free(ptr);    \
    ptr = nullptr;\
}

#endif // MACROS_H