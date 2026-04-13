#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef float f32;
typedef double f64;

typedef struct complex {
    f32 re;
    f32 im;
} complex;

typedef union numeric {
    complex c;
    f64 d;
} numeric;

typedef struct double_or_complex {
    numeric val;
    bool is_double;
} double_or_complex;

complex mult(complex a, complex b);
double_or_complex mul(double_or_complex a, double_or_complex b);
void print_complex(complex a);
void print_double_or_complex(double_or_complex a);

int main(void) {
    double_or_complex a = {.val.d = 5.672, .is_double = false};
    double_or_complex b = {.val.d = 10.0, .is_double = false};
    double_or_complex c = mul(a, b);
    printf("%ld\n", sizeof(double_or_complex));
    print_double_or_complex(c);
    return 0;
}

complex mult(complex a, complex b) {
    return (complex) {a.re*b.re - a.im*b.im, a.im*b.re + a.re*b.im};
}

void print_complex(complex a) {
    printf((a.im < 0 ? "%g%gi\n" : "%g+%gi\n"), a.re, a.im);
}

double_or_complex mul(double_or_complex a, double_or_complex b) {
    if(a.is_double != b.is_double) return (double_or_complex) {0};

    if (a.is_double)
        return (double_or_complex) {.val.d = a.val.d*b.val.d, .is_double = true};
    else 
        return (double_or_complex) {.val.c = mult(a.val.c, b.val.c), .is_double = false};
}

void print_double_or_complex(double_or_complex a) {
    if (a.is_double)
        printf("%g\n", a.val.d);
    else
        print_complex(a.val.c);
}

