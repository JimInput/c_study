#ifndef __GTREE_H__
#define __GTREE_H__

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

typedef struct node NODE;

struct node {
    int   child_no;
    DATA  d;
    NODE *sib;
};

typedef struct {
    int out;
    int in;
} PAIR;

typedef NODE *GTREE;

GTREE new_gnode(void);
GTREE init_gnode(DATA d1, int num, GTREE sibs);
void  preorder_g(GTREE t[], int ind);
void  buildtree(PAIR edges[], DATA d[], int n, GTREE t[]);
void  free_gtree(GTREE t[], int ind);

#endif