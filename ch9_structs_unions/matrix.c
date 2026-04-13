#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 5
#define C 3


typedef double number;
typedef number matrix[R][C];

void generate_matrix(matrix m);
void print_matrix(matrix m);

int main(void) {
    srand(time(NULL));

    matrix a;
    generate_matrix(a);

    print_matrix(a);

    return 0;
}

void generate_matrix(matrix m) {
    int i, j;
    for (i = 0; i < R; ++i) {
        for (j = 0; j < C; ++j) {
            m[i][j] = (number) rand() / RAND_MAX *1000.0 - 500.0;
        }
    }
}

void print_matrix(matrix m) {
    int i, j;
    for (i = 0; i < R; ++i) {
        for (j = 0; j < C; ++j) {
            printf("%-10g ", m[i][j]);
        }
        putchar('\n');
    }
}


