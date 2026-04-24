#include "heap.h"

i32  parent(i32 idx) { return (idx - 1) / 2; }
i32  left_child(i32 idx) { return 2 * idx + 1; }
i32  right_child(i32 idx) { return 2 * idx + 2; }
bool compare(data d1, data d2) { return d1 < d2; }

void swap(data *a, data *b) {
    data tmp = *a;
    *a = *b;
    *b = tmp;
}

void upheap(heap *h, i32 idx) {
    if (idx == 0)
        return;
    i32 p = parent(idx);
    if (compare(h->arr[idx], h->arr[p])) {
        // printf("%d swap %d\n", h->arr[idx], h->arr[p]);
        swap(&h->arr[idx], &h->arr[p]);
        upheap(h, p);
    }
}

void downheap(heap *h, i32 idx) {
    i32 l = left_child(idx);
    i32 r = right_child(idx);

    if (l > h->bot)
        return;

    i32 best = l;

    if (r <= h->bot && compare(h->arr[r], h->arr[l]))
        best = r;

    if (compare(h->arr[best], h->arr[idx])) {
        swap(&h->arr[best], &h->arr[idx]);
        downheap(h, best);
    }
}

heap *initialize() {
    heap *h = (heap *)calloc(1, sizeof(heap));
    h->bot = -1;
    return h;
}

void free_heap(heap *h) { free(h); }

void push(heap *h, data d) {
    h->bot++;
    h->arr[h->bot] = d;
    // print_list(h->arr, h->bot);
    upheap(h, h->bot);
}

data pop(heap *h) {
    data item = h->arr[0];
    swap(&h->arr[0], &h->arr[h->bot]);
    h->bot--;
    downheap(h, 0);
    return item;
}

void print_list(data a[], i32 n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    putchar('\n');
}

void heap_sort(data a[], i32 n) {
    heap *h = initialize();
    for (i32 i = 0; i < n; ++i)
        push(h, a[i]);
    for (i32 i = 0; i < n; ++i)
        a[i] = pop(h);
}
