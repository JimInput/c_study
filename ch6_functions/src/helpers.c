#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int* p, int* q) {
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}

void bubble(int a[], int n) {
    int i, j;
    char finished;
    for (i = 0; i < n; ++i) {
        finished = 1;
        for (j = 0; j < n-i-1; ++j) {
            if (a[j] > a[j+1]) {
                finished = 0;
                swap(&a[j], &a[j+1]);
            }
        }
        if (finished)
            break;
    }
}

char is_sorted(int a[], int n) {
    int i;
    for (i = 0; i < n-1; ++i) {
        if (a[i] > a[i+1])
            return 0;
    }
    return 1;
}

void fprint_arr(FILE* ofp, int a[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        fprintf(ofp, "%d ", a[i]);
    }
    fprintf(ofp, "\n");
}

void merge(int a[], int b[], int c[], int m, int n) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < m) {
        c[k++] = a[i++];
    }
    while (j < n) {
        c[k++] = b[j++];
    }
}

void mergesort(int key[], int n) {
    int j, k, m, *w;
    
    w = (int *) calloc(n, sizeof(int));
    assert(w != NULL);
    for (k = 1; k < n; k *= 2) {
        for (j = 0; j < n - k; j += 2*k)
            merge(key+j, key+j+k, w+j, k, (j + 2*k <= n ? k : (n-j-k)));
        for (j = 0; j < n; ++j)
            key[j] = w[j];
    }
    free(w);
}