#include "polish.h"

void fill(stack *stk, const char *str) {
    const char *p = str;
    char c1, c2;
    bool b1, b2;
    data d;
    stack tmp;

    initialize(stk);
    initialize(&tmp);

    while (*p != '\0') {
        while (isspace(*p) || *p == ',')
            ++p;
        b1 = (bool) ((c1 = *p) == '+' || c1 == '-' || c1 =='*');
        b2 = (bool) ((c2 = *(p+1)) == ',' || c2 == '\0');
        if (b1 && b2) {
            d.kind = operator;
            d.u.op = c1;
        } else {
            d.kind = value;
            assert(sscanf(p, "%d", &d.u.val) == 1);
        }
        if (!full(&tmp))
            push(d, &tmp);
        while (*p != ',' && *p != '\0')
            ++p;
    }

    while (!empty(&tmp)) {
        d = pop(&tmp);
        if (!full(stk))
            push(d, stk);
    }
}