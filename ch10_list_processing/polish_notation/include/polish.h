#ifndef __POLISH_H__
#define __POLISH_H__

/* A linked list implementation of a Polish stack. */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY 0
#define FULL 10000

typedef struct {
    enum {operator, value} kind;
    union {
        char op;
        int val;
    } u;
} data;

typedef struct elem {
    data d;
    struct elem *next;
} elem;

typedef struct stack {
    int cnt;
    elem *top;
} stack;

bool empty(const stack *stk);
int evaluate(stack *polish);
void fill(stack *stk, const char *str);
bool full(const stack *stk);
void initialize(stack *stk);
data pop(stack *stk);
void prn_data(data *dp);
void prn_stack(stack *stk);
void push(data d, stack *stk);
data top(stack *stk);


#endif