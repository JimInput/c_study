#include <stdio.h>
#include <math.h>

#define SQ(x) ((x) * (x))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define CUBE(x) (SQ(x) * (x))
#define F_POW(x) sqrt(sqrt(CUBE(x)))

int main(void) {
    printf("%d\n", SQ(4));
    printf("%d\n", min(8, -5));
    printf("%d\n", min4(1, 2, 3, 4));
    printf("%g\n", F_POW(3));
    printf("%d\n", __LINE__);
    printf("%s\n", __TIME__);
    printf("%s\n", __FILE__);
    printf("%s\n", __DATE__);
    return 0;
}