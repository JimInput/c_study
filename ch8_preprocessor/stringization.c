#include <stdio.h>

#define PRN(x) printf(#x"\n")
#define PRN3(a,b,c) printf("x has value %g and y has value %g and z has value %g\n", a, b, c)
#define X(i) x ## i // this becomes x1, x2, x3, ... xn
#define MAX(x, y, z) (((x) > (y)) ? (((x) > (z)) ? (x) : (z)) : (((y) > (z)) ? (y) : (z)))

int main(void) {
    PRN(Hello from main());
    int X(1) = 3;
    printf("%d\n", x1);

    PRN3(1.1, 2.2, 3.3);

    printf("%d\n", MAX(-1, -40, 67));
    return 0;
}
