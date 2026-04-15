#include "gtree.h"

int main(void) {
    GTREE t[9];
    t[0] = init_gnode('a', 1, NULL);
    t[1] = init_gnode('b', 2, NULL);
    t[1]->sib = init_gnode('f', 6, NULL);
    t[1]->sib->sib = init_gnode('h', 8, NULL);

}