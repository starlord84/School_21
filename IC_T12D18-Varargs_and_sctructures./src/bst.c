#include "bst.h"

t_btree *bstree_create_node(int item) {
    t_btree *tmp = malloc(sizeof(t_btree));
    tmp -> item = item;
    tmp -> parent = NULL;
    tmp -> left = tmp -> right = NULL;
    return tmp;
}
