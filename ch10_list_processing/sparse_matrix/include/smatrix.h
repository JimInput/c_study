#ifndef __SMATRIX_H__
#define __SMATRIX_H__

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define EPS 1e-6

typedef int32_t data;

typedef struct Node    Node;
typedef struct RHead   RHead;
typedef struct CHead   CHead;
typedef struct SMatrix SMatrix;

struct Node {
    Node *right;
    Node *down;
    int   row;
    int   col;
    data  d;
};

struct RHead {
    Node *right;
    int   row;
};

struct CHead {
    Node *down;
    int   col;
};

struct SMatrix {
    RHead *rows;
    CHead *cols;
    int    nrows;
    int    ncols;
};

SMatrix *initialize_smatrix(int nrows, int ncols);
Node    *initialize_node(int row, int col, data d);
void     insert_node(SMatrix *m, data d, int row, int col);
void     fill_smatrix(SMatrix *m, data *d, int nrows, int ncols);
void     free_smatrix(SMatrix *m);

#endif