#include <stdio.h>
#include <stdint.h>

typedef uint32_t u32;
typedef u32 set;

set Union(set a, set b);
set intersection(set a, set b);
set complement(set a);
void display(set a);

int main(void) {
    set a = 0x7;
    set b = 0x55;

    display(a);
    display(b);
    display(Union(a,b));
    display(intersection(a,b));
    display(complement(a));

    return 0;
}

set Union(set a, set b) {
    return a | b;
}

set intersection(set a, set b) {
    return a & b;
}

set complement(set a) {
    return ~a;
}

void display(set a) {
    int item = 1;
    
    while (a > 0) {
        if ((a & 1) == 1)
            printf("%d ", item);
        ++item;
        a >>= 1;
    }
    putchar('\n');
}