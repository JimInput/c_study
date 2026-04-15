#include "stack.h"

int main(void) {
    char str[] = "My name is Jimmy Padilla!";
    int i;
    stack s;

    initialize(&s);
    printf("In the string: %s\n", str);
    for (i = 0; str[i] != '\0'; ++i)
        if (!full(&s))
            push(str[i], &s);
    printf("From the stack: ");
    while (!empty(&s))
        putchar(pop(&s));
    putchar('\n');
    return 0;
}