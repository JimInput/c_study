#ifndef CH6FUNCS_H
#define CH6FUNCS_H
#include <stdio.h>

    void swap(int *p, int *q);
    void bubble(int a[], int n);
    char is_sorted(int a[], int n);
    void fprint_arr(FILE* ofp, int a[], int n);
    void merge(int a[], int b[], int c[], int m, int n);
    void mergesort(int key[], int n);
#endif