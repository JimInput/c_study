/*
Exercise 7.2
Alice, Betty and Carole all vote on 16 separate referenda. Assume that each individual's vote is stored bitwise in a 16-bit integer. Write a function definition that begins
            short majority(short a, short b, short c)
This function should take as input the votes of Alice, Betty and Carole stored in a, b, and c, respectively. It should return the bitwise majority of a, b, and c.
*/

#include <stdio.h>
#include <limits.h>
#include <assert.h>

short majority(short a, short b, short c);
void bit_print(short a);

int main(void) {
    short alice =   0b110010101101;
    short betty =   0b001010000110;
    short carole =  0b010010100011;

    assert(majority(alice, betty, carole) == 0b010010100111);

    bit_print(alice); putchar('\n');
    bit_print(betty); putchar('\n');
    bit_print(carole); putchar('\n');
    printf("%17s\n", "-----------------");
    bit_print(majority(alice, betty, carole)); putchar('\n');
    return 0;
}

short majority(short a, short b, short c) {
    return (a & b) | (b & c) | (a & c);
}

void bit_print(short a) {
    int n = sizeof(short) * CHAR_BIT;
    int mask = 1 << (n-1);

    for (int i = 1; i <= n; i++) {
        putchar(((a & mask) == 0) ? '0' : '1');
        a <<= 1;
        if ((i % CHAR_BIT == 0) && i < n)
            putchar(' ');
    }
}