#ifndef __GTREE_H__
#define __GTREE_H__

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

typedef struct node {
    int child_no;
    DATA d;
    struct node *sib;
} NODE;

typedef NODE *GTREE;

GTREE new_gnode(void);
GTREE init_gnode(DATA d1, int num, GTREE sibs);

#endif