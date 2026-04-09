#include "bits.h"

void bit_print(int a) {
    int i;
    int n = sizeof(int) * CHAR_BIT;     // bytes * num bits in a byte
    int mask = 1 << (n-1);              // mask = 100...0

    for (i = 1; i <= n; ++i) {
        putchar(((a & mask) == 0) ? '0' : '1');
        a <<= 1;
        if (i % CHAR_BIT == 0 && i < n)
            putchar(' ');
    }
}

int pack(char a, char b, char c, char d) {
    int p = a;
    p = (p << CHAR_BIT) | b;
    p = (p << CHAR_BIT) | c;
    p = (p << CHAR_BIT) | d;

    return p;
}

char unpack(int p, int k) {
    int n = k * CHAR_BIT;
    unsigned mask = 0xFF;

    mask <<= n;
    return ((p & mask) >> n);
}

int main(void) {
    printf("abcd = ");
    bit_print(pack(1, 5, 6, 127));
    putchar('\n');

    bit_print(unpack(pack(1, 3, 46, 127), 2));
    putchar('\n');
    return 0;
}