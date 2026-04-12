#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define swap(x, y) { int t; t = x; x = y; y = t; }
#define N 10000
#define DEBUG

#ifdef DEBUG
    #define DEBUG_ONLY(...)  __VA_ARGS__;
#else
    #define DEBUG_ONLY(...) 
#endif

typedef int i32;
typedef unsigned long u64;

void quicksort(i32 *, i32 *);
i32 *partition(i32 *left, i32 *right, i32 pivot);
void print_array(i32 *a, u64 n);
bool is_sorted(i32 *a, u64 n);

i32 main(void) {
    i32 a[N], i;

    srand(time(NULL));
    for (i = 0; i < N; ++i)
        a[i] = rand() % 1000;
    quicksort(a, a + N - 1);
    DEBUG_ONLY(printf("Sorted: %s\n", is_sorted(a, N) ? "TRUE" : "FALSE"))
    return 0;
}

void quicksort(i32 *left, i32 *right) {
    if (left >= right) return;
    i32 *p, pivot = *right;
    p = partition(left, right, pivot);
    quicksort(left, p-1);
    quicksort(p+1, right); 
}

i32 *partition(i32 *left, i32 *right, i32 pivot) {
    i32 *i = left;
    for (i32 *j = left; j < right; ++j)
        if (*j < pivot) {
            swap(*i, *j);
            i++;
        }
    swap(*i, *right);
    return i;
}

void print_array(i32 *a, u64 n) {
    u64 i;
    for (i = 0; i < n; ++i)
        printf("%d ", a[i]);
    putchar('\n');
}

bool is_sorted(i32 *a, u64 n) {
    u64 i;
    for (i = 0; i < n-1; ++i)
        if (a[i] > a[i+1])
            return false;
    return true;
}
