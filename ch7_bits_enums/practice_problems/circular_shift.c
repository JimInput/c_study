/*
Exercise 7.3
Write a function definition that begins
    int circular_shift(int a, int n)
This function should left-shift a by n positions, where the high-order bits are 
reintroduced as the low-order bits. Here are two examples of a circular shift 
operation defined for a char instead of an int:
    10000001    circular shift 1 yields     00000011
    01101011    circular shift 3 yields     01011011
*/

#include <stdio.h>
#include <limits.h>

int circular_shift(int a, int n);
void bit_print(int a);

int main(void) {
    int a = 0xFAB12345;

    bit_print(a); putchar('\n');
    a = circular_shift(a, 12);
    bit_print(a); putchar('\n');
    return 0;
}
int circular_shift(int a, int n) {
    int n_bits = sizeof(int) * CHAR_BIT;
    unsigned val = (unsigned) a;
    return (val << n) | (val >> (n_bits - n));
}

void bit_print(int a) {
    int n = sizeof(int) * CHAR_BIT;
    int mask = 1 << (n-1);

    for (int i = 1; i <= n; ++i) {
        putchar((a&mask)==0 ? '0' : '1');
        a <<= 1;
        if (i % CHAR_BIT == 0 && i < n)
            putchar(' ');
    }
}