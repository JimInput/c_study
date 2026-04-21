#include "gtree.h"

GTREE new_gnode(void) { return malloc(sizeof(NODE)); }

GTREE init_gnode(DATA d1, int num, GTREE sibs) {
    GTREE tmp = new_gnode();
    tmp->d = d1;
    tmp->child_no = num;
    tmp->sib = sibs;
    return tmp;
}

void preorder_g(GTREE t[], int ind) {
    GTREE tmp;

    tmp = t[ind];
    while (tmp != NULL) {
        printf("%c %d\n", tmp->d, tmp->child_no);
        preorder_g(t, tmp->child_no);
        tmp = tmp->sib;
    }
}

void buildtree(PAIR edges[], DATA d[], int n, GTREE t[]) {
    int i;
    int x, y;

    for (i = 0; i < n; ++i)
        t[i] = NULL;
    for (i = 0; i < 1; ++i) {
        x = edges[i].out;
        y = edges[i].in;
        t[x] = init_gnode(d[x], y, t[y]);
    }
}

void free_gtree(GTREE t[], int ind) {
    GTREE tmp;

    while (t[ind] != NULL) {
        free_gtree(t, t[ind]->child_no);
        tmp = t[ind];
        ind++;
        free(tmp);
    }
}
