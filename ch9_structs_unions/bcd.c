#include <stdio.h>

#define NUM_DIGIT 8

typedef struct { // d0 - Least Significant, d7 - Most Significant
    unsigned d0: 4, d1: 4, d2: 4, d3: 4, 
             d4: 4, d5: 4, d6: 4, d7: 4; 
} word_digits;

typedef union {
    int word;
    word_digits digit;
} bcd;

// a 32 bit work can represent an 8-digit decimal number

bcd int_to_bcd(int a);
int bcd_to_int(bcd a);
void print_bcd(bcd a);

int main(void) {
    int i = 28890;
    bcd b = int_to_bcd(i);
    print_bcd(b);
    int j = bcd_to_int(b);
    printf("%d\n", j);

    return 0;
}

bcd int_to_bcd(int a) {
    int i;
    bcd b;
    b.digit.d0 = a % 10;
    a /= 10;
    b.digit.d1 = a % 10;
    a /= 10;
    b.digit.d2 = a % 10;
    a /= 10;
    b.digit.d3 = a % 10;
    a /= 10;
    b.digit.d4 = a % 10;
    a /= 10;
    b.digit.d5 = a % 10;
    a /= 10;
    b.digit.d6 = a % 10;
    a /= 10;
    b.digit.d7 = a % 10;
    a /= 10;
    return b;
}

int bcd_to_int(bcd a) {
    int sum;
    sum =  a.digit.d7 * 10000000 +
           a.digit.d6 * 1000000  +
           a.digit.d5 * 100000   +
           a.digit.d4 * 10000    +
           a.digit.d3 * 1000     +
           a.digit.d2 * 100      +
           a.digit.d1 * 10       +
           a.digit.d0 * 1;
    return sum;
}

void print_bcd(bcd a) {
    putchar(a.digit.d7+'0');
    putchar(a.digit.d6+'0');
    putchar(a.digit.d5+'0');
    putchar(a.digit.d4+'0');
    putchar(a.digit.d3+'0');
    putchar(a.digit.d2+'0');
    putchar(a.digit.d1+'0');
    putchar(a.digit.d0+'0');
    putchar('\n');
}
