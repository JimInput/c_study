/* The basic stack routines. */

#include "stack.h"

void initialize(stack *stk) {
    stk -> cnt = 0;
    stk -> top = NULL;
}

void push(data d, stack *stk) {
    elem *p = malloc(sizeof(elem));
    p->d = d;
    p->next = stk->top;
    stk->top = p;
    stk->cnt++;
}

data pop(stack *stk) {
    data v;
    elem *p;

    v = stk->top->d;
    p = stk->top;
    stk->top = stk->top->next;
    stk->cnt--;
    free(p);
    return v;
}

data top(stack *stk) {
    return stk->top->d;
}

bool empty(const stack *stk) {
    return (bool) (stk->cnt == EMPTY);
}

bool full(const stack *stk) {
    return (bool) (stk->cnt == FULL);
}
