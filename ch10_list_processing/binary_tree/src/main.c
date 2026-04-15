#include "tree.h"

int main(void) {
    DATA a[] = "GDIBFHJACE";
    BTREE t = create_tree(a, 0, sizeof(a)/sizeof(DATA));
    inorder(t); putchar('\n');
    preorder(t); putchar('\n');
    postorder(t); putchar('\n');
    free_tree(t);
    t = NULL;
    
    return 0;
}