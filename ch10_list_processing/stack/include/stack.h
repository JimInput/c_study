#ifndef __STACK_H__
#define __STACK_H__

/* A linked list implementation of a stack. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY 0
#define FULL 10000

typedef char data;

typedef struct elem {
    data d;
    struct elem *next;
} elem;

typedef struct stack {
    int cnt;
    elem *top;
} stack;

void initialize(stack *stk);
void push(data d, stack *stk);
data pop(stack *stk);
data top(stack *stk);
bool empty(const stack *stk);
bool full(const stack *stk);

#endif