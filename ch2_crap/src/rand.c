#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main(void) {
    srand(time(NULL));

    printf("%d\n", RAND_MAX);

    printf("%d\n", rand()%2);
    printf("%lf\n", (double) rand() / RAND_MAX);
    printf("%d\n", MAX(5, 87));
    printf("%lf\n", fabs(sqrt(9)));
    return 0;
}