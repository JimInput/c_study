#include "smatrix.h"

SMatrix *initialize_smatrix(int nrows, int ncols) {
    SMatrix *m = (SMatrix *)calloc(1, sizeof(SMatrix));
    m->rows = (RHead *)calloc(nrows, sizeof(RHead));
    m->cols = (CHead *)calloc(ncols, sizeof(CHead));
    for (int i = 0; i < ncols; ++i) {
        m->rows[i].right = NULL;
        m->rows[i].row = i;
    }
    for (int i = 0; i < ncols; ++i) {
        m->cols[i].down = NULL;
        m->cols[i].col = i;
    }
    m->nrows = nrows;
    m->ncols = ncols;
    return m;
}

Node *initialize_node(int row, int col, data d) {
    Node *n = (Node *)calloc(1, sizeof(Node));
    n->row = row;
    n->col = col;
    n->d = d;
}

void insert_node(SMatrix *m, data d, int row, int col) {
    Node *curr = m->rows[row].right;
    Node *prev = NULL;

    // --- SEARCH FIRST (row list) ---
    while (curr && curr->col < col) {
        prev = curr;
        curr = curr->right;
    }

    if (curr && curr->col == col) {
        curr->d = d;
        return;
    }

    // --- NOW allocate ---
    Node *new_node = initialize_node(row, col, d);

    // --- INSERT INTO ROW ---
    if (!prev) {
        new_node->right = m->rows[row].right;
        m->rows[row].right = new_node;
    } else {
        new_node->right = curr;
        prev->right = new_node;
    }

    // --- INSERT INTO COLUMN ---
    curr = m->cols[col].down;
    prev = NULL;

    while (curr && curr->row < row) {
        prev = curr;
        curr = curr->down;
    }

    if (!prev) {
        new_node->down = m->cols[col].down;
        m->cols[col].down = new_node;
    } else {
        new_node->down = curr;
        prev->down = new_node;
    }
}

void fill_smatrix(SMatrix *m, data *d, int nrows, int ncols) {
    assert(m->nrows == nrows && m->ncols == ncols);
    for (int i = 0; i < nrows; ++i)
        for (int j = 0; j < ncols; ++j) {
            data val = d[i*ncols+j];
            // If value is sufficiently large we should add to the smatrix.
            if (fabs(val) > EPS)
                insert_node(m, val, i, j);
        }
}

void free_smatrix(SMatrix *m) {
    for (int i = 0; i < m->nrows; ++i) {
        Node *tmp = m->rows[i].right;
        while (tmp) {
            Node *prev = tmp;
            tmp = tmp->right;
            free(prev);
        }
    }
    free(m->rows);
    free(m->cols);
    free(m);
}
