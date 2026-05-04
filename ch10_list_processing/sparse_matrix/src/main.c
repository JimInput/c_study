#include "smatrix.h"

int main(void) {
    SMatrix *m = initialize_smatrix(2, 6);

    data d[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    fill_smatrix(m, d, 2, 6);

    free_smatrix(m);

    return 0;
}