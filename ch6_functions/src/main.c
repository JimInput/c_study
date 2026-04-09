#include <stdio.h>

#include "helpers.h"

int main(void) {
    int a[] = {4, 3, 1, 67, 55, 8, 0, 4, -5, 37, 7, 4, 2, 9, 1, -1, -3};
    int n = sizeof(a) / sizeof(int);
    fprint_arr(stdout, a, n);
    mergesort(a, n);
    fprint_arr(stdout, a, n);
    
    return 0;
}