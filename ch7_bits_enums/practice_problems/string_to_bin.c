/*
Exercise 7.7
Write a function that takes as its input a string of decimal integers.
Each character in the string can be throught of as a decimal digit. The
digits should be converted to 4-bit binary strings and packed into an int. 
If an int has 32 bits, then eight digits can be packed into it.
*/

#include <stdio.h>
#include <string.h>

#define CHAR_BIT 8

typedef const int cint;

int str_to_bcd(char* s);
void bcd_to_str(char* s, int a);
void bit_print(int a);

int main(void) {
    char* s = "12345678";
    char rev[9];
    int a = str_to_bcd(s);
    bit_print(a); putchar('\n');
    bcd_to_str(rev, a);
    printf("%s\n", rev);
    return 0;
}

int str_to_bcd(char* s) {
    cint n = strlen(s);
    int bcd = 0;
    for (int i = 0; i < n && i < 8; i++)
        bcd = (bcd << 4) | (s[i]-'0');
    return bcd;
}

void bcd_to_str(char* s, int a) {
    cint n = sizeof(int) * CHAR_BIT;
    for (int i = 0; i < 8; i++) {
        s[i] = ((a >> (28-4*i)) & 0xF)+'0';
    }
    s[8] = '\0';
}

void bit_print(int a) {
    cint n = sizeof(int) * CHAR_BIT;
    int mask = 1 << (n-1);

    for (int i = 1; i <= n; ++i) {
        putchar((a&mask)==0 ? '0' : '1');
        a <<= 1;
        if ((i % CHAR_BIT == 0) && i < n)
            putchar(' ');
    }

}