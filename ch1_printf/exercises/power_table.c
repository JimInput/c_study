#include <stdio.h>
#include <stdlib.h>

int power(int x, int y);

int main(void) {
    int n;
    printf("Input the number of rows to generate:  ");
    if (scanf("%d", &n) != 1) {
        printf("\nInvalid input. Exiting...\n");
        exit(1);
    }

    printf(":::::  A TABLE OF POWERS  :::::\n");
    printf("%7s  %6s  %9s  %9s  %9s\n%7s  %6s  %9s  %9s  %9s\n", 
        "Integer", "Square", "3rd power", "4th power", "5th power",
        "-------", "------", "---------", "---------", "---------");

    if (n < 0) 
        n = -n;
    for (int i = 1; i <= n; ++i) {
        printf("%7d  %6d  %9d  %9d  %9d\n",
            i, power(i, 2), power(i, 3), power(i, 4), power(i, 5));
    }
    return 0;
}

int power(int x, int y) {
    int product = 1;
    for (int i = 0; i < y; i++) {
        product *= x;
    }
    return product;
}