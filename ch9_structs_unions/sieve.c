#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 10000
#define WORD_BIT (CHAR_BIT*sizeof(unsigned))

typedef unsigned int u32;

void sieve(u32 *a);
void bit_print(u32 a);
void print_bit_arr(u32 *a, u32 n);
void print_sieve_results(u32 *a);
bool is_prime(u32 a, u32 *p_arr);

int main(void) {
    u32 a[N] = {0};

    sieve(a);

    print_sieve_results(a);


    return 0;
}

void sieve(u32 *a) {
    u32 i, j;
    a[0] |= 1u;
    for (i = 1; i < N*WORD_BIT; ++i) {
        if ((a[i/WORD_BIT] & (0x1u << (i % WORD_BIT))) == 0) {
            for (j = 2*(i+1)-1; j < N*WORD_BIT; j+=(i+1)) 
                a[(j)/WORD_BIT] |= (0x1u << ((j) % WORD_BIT));
        }
    }
}

void bit_print(u32 a) {
    int i;

    for (i = 1; i <= WORD_BIT; ++i) {
        printf("%d", (a & 0x1));
        a >>= 1;
        if (i % 8 == 0)
            putchar(' ');
    }
}

void print_bit_arr(u32 *a, u32 n) {
    int i;
    for (i = 0; i < n; ++i) {
        bit_print(a[i]);
        printf("\n");
    }
}

void print_sieve_results(u32 *a) {
    u32 i;
    for (i = 0; i < N*WORD_BIT; ++i) {
        if ((a[i/WORD_BIT] & (0x1u << (i % WORD_BIT))) == 0) {
            printf("%d\n", i+1);
        }
    }
}

bool is_prime(u32 a, u32 *p_arr) {
    if (a <= 1 || a > N*WORD_BIT) return false;
    u32 i;
    for (i = 0; i < N*WORD_BIT; ++i) {
        if ((p_arr[i/WORD_BIT] & (0x1 << (i % 32))) == 0)
            if (a == i+1)
                return true;
    }
    return false;
}
