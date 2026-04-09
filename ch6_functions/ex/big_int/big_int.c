#include <assert.h>
#include <stdio.h>

#define N 20

typedef const char cchr;

void add(int sum[], int a[], int b[]);
void wrt(cchr *s, int a[]);

int main(void) {
    int a[N] = {7, 5, 9, 8, 9, 7, 5, 0, 0, 9, 9, 0, 8, 8};
    int b[N] = {7, 7, 5, 3, 1, 2, 8, 8, 9, 6, 7, 7};
    int sum[N];
    int ndigits;

    add(sum, a, b);
    wrt("Integer a: ", a);
    wrt("Integer b: ", b);
    wrt("      Sum: ", sum);
    return 0;
}

void add(int sum[], int a[], int b[]) {
    int carry = 0;
    int i;

    for (i = 0; i < N; ++i) {
        sum[i] = a[i] + b[i] + carry;
        if (sum[i] < 10)
            carry = 0;
        else {
            carry = sum[i] / 10;
            sum[i] %= 10;
        }
    }
}

void wrt(cchr *s, int a[]) {
    int i;

    printf("%s", s);
    for (i = N-1; i > 0 && a[i] == 0; --i)
        putchar(' ');

    for (; i>= 0; --i)
        printf("%d", a[i]);
    putchar('\n');
}