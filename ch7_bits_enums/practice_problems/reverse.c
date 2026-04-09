/*
Exercise 7.5
Write a fucntion that will reverse the bit representation of an int.
Here are two examples of a reversing operation defined for a char instead
of an int:
    01110101    reversed yields     10101110
    10101111    reversed yields     11110101
*/

#include <stdio.h>
#include <limits.h>

int reverse_bits(int a);
void bit_print(int a);

int main(void) {
    int a = 0x7000A00F;
    int r = reverse_bits(a);

    printf("%d\n", a);
    bit_print(a); putchar('\n');
    printf("%d\n", r);
    bit_print(reverse_bits(a)); putchar('\n');

    return 0;
}

int reverse_bits(int a) {
    int n = sizeof(int) * CHAR_BIT;
    int tmp = 0;

    for (int i = 0; i < n; ++i) {
        tmp = (tmp << 1) | (a & 1);
        a >>= 1;
    }

    return tmp;
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