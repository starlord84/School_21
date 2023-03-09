#ifndef SRC_BST_H_
#define SRC_BST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct t_btree {
    int item;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} t_btree;

t_btree *bstree_create_node(int item);

#endif  // SRC_BST_H_
