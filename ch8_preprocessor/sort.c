#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef double f64;
typedef int i32;
typedef unsigned long u64;
typedef int (*cfunc)(const void*, const void*);

void generate_array(f64 *a, size_t n);
void print_array(f64 *a, size_t n);
f64 decimal_part(f64 x);
int compare_decimal_part(f64 *p, f64 *q);
int compare_double(f64 *p, f64 *q);

int main(void) {
    srand(time(NULL));

    const u64 n = 50;

    f64 a[n];
    generate_array(a, n);
    print_array(a, n);
    qsort(a, n, sizeof(f64), (cfunc) compare_double);
    print_array(a, n);

    return 0;
}

void generate_array(f64 *a, size_t n) {
    u64 i;
    for (i = 0; i < n; i++)
        a[i] = (f64) rand() / RAND_MAX * 1000.0 - 500.0;
}

void print_array(f64 *a, size_t n) {
    u64 i;
    for (i = 0; i < n; i++)
        printf("%g ", a[i]);
    putchar('\n');
}


f64 decimal_part(f64 x) {
    return x - (i32) x;
}

int compare_decimal_part(f64 *p, f64 *q) {
    f64 x = decimal_part(*p) - decimal_part(*q);
    return ((x == 0.0) ? 0 : (x < 0.0) ? -1 : 1);
}

int compare_double(f64 *p, f64 *q) {
    return (i32) (*p - *q);
}
