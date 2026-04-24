#include "heap.h"

int main() {
    data  a[] = {-1, 3, 4, 5, 6, 2, 3, 4};
    i32   n = sizeof(a) / sizeof(data);

    heap_sort(a, n);

    print_list(a, n);

    return 0;
}