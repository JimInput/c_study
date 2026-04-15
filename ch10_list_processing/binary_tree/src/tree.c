#include "tree.h"

void inorder(BTREE root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->d);
        inorder(root->right);
    }
}

void preorder(BTREE root) {
    if (root != NULL) {
        printf("%c ", root->d);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BTREE root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->d);
    }
}

BTREE init_node(DATA d1, BTREE p1, BTREE p2) {
    BTREE t = malloc(sizeof(NODE));
    t->d = d1;
    t->left = p1;
    t->right = p2;
    return t;
}

BTREE create_tree(DATA a[], int i, int size) {
    if (i >= size || a[i] == '\0')
        return NULL;
    else
        return init_node(a[i], 
            create_tree(a, 2*i+1, size),
            create_tree(a, 2*i+2, size));
}

void free_tree(BTREE t) {
    if (t == NULL)
        return;
    free_tree(t->left);
    free_tree(t->right);
    free(t);
}
