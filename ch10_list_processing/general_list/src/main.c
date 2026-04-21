#include "gtree.h"

#define N 9

int main(void) {
    GTREE t[N];

    PAIR edges[N] = {{0, 1}, {1, 2}, {2, 3}, {1, 4}, {4, 5}, {5, 6}, {2, 7}};
    DATA data[N] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

    buildtree(edges, data, N, t);

    preorder_g(t, 0);
    free_gtree(t, 0);
    return 0;
}