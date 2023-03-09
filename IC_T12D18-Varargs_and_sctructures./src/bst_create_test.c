#include "bst.h"

int main() {
    t_btree *root1 = bstree_create_node(21);

    if (root1->left == NULL && root1->right == NULL && root1->item == 21) {
        printf("root1->left = NULL\n");
        printf("root1->right = NULL\n");
        printf("root1->item = 21\n");
    } else {
        printf("FAIL\n");
    }
    t_btree *root2 = bstree_create_node(42);
    if (root2->left == NULL && root2->right == NULL && root2->item == 42) {
        printf("root1->left = NULL\n");
        printf("root1->right = NULL\n");
        printf("root1->item = 21");
    } else {
        printf("FAIL\n");
    }
    free(root1);
    free(root2);
    return 0;
}
