#include "gtree.h"

GTREE new_gnode(void) {
    return malloc(sizeof(NODE));
}

GTREE init_gnode(DATA d1, int num, GTREE sibs) {
    GTREE tmp = new_gnode();
    tmp->d = d1;
    tmp->child_no = num;
    tmp->sib = sibs;
    return tmp;
}
