#ifndef __HEAP_H__
#define __HEAP_H__

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 256
#define EMPTY   -1
#define FULL    (MAX_LEN - 1)

typedef int32_t i32;

typedef i32 data;

typedef struct heap {
    data arr[MAX_LEN];
    i32  bot;
} heap;

i32   parent(i32 idx);
i32   left_child(i32 idx);
i32   right_child(i32 idx);
bool  compare(data d1, data d2);
void  swap(data *a, data *b);
void  upheap(heap *h, i32 idx);
void  downheap(heap *h, i32 idx);
heap *initialize();
void  free_heap(heap *h);
void  push(heap *h, data d);
data  pop(heap *h);
void  print_list(data a[], i32 n);
void  heap_sort(data a[], i32 n);

#endif