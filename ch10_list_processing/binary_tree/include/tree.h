#ifndef __TREE_H__
#define __TREE_H__

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

typedef struct node {
    DATA d;
    struct node *left;
    struct node *right;
} NODE;

typedef NODE *BTREE;

void inorder(BTREE root);
void preorder(BTREE root);
void postorder(BTREE root);

BTREE init_node(DATA d1, BTREE p1, BTREE p2);
BTREE create_tree(DATA a[], int i, int size);
void free_tree(BTREE t);

#endif