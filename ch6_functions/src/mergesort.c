#include <stdio.h>
#include <stdlib.h>

void mergesort(int a[], int start, int end);
void merge(int a[], int b[], int c[], int n, int m);
void fprint_arr(FILE* ofp, int a[], int n);

int main(void) {
    int a[] = {31, -6, 5, 8, 9, -2, 3, 4, 1, 8, 5};
    int n = sizeof(a) / sizeof(int);
    
    mergesort(a, 0, n);

    fprint_arr(stdout, a, n);
    
    return 0;
}

void mergesort(int a[], int start, int end) {
    if (end-start <= 1) return;
    int m = (start + end) / 2;
    mergesort(a, start, m);
    mergesort(a, m, end);

    int *w = calloc(end-start, sizeof(int));
    merge(a+start, a+m, w, m-start, end-m);

    for (int i = 0; i < end-start; ++i) {
        a[start+i] = w[i];
    }
    free(w);
}

void merge(int a[], int b[], int c[], int n, int m) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < n) {
        c[k++] = a[i++];
    }
    while (j < m) {
        c[k++] = b[j++];
    }
}

void fprint_arr(FILE* ofp, int a[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        fprintf(ofp, "%d ", a[i]);
    }
    fprintf(ofp, "\n");
}