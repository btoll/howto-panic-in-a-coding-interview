#include "../bst.c"

void traverse(struct tree_node *n, int *k, int nodes[]) {
    if (n == NULL) return;
    traverse(n->left, k, nodes);
    nodes[*k] = n->val;
    *k = *k + 1;
    traverse(n->right, k, nodes);
}

int main(int argc, char **argv) {
    int nodes [] = { 100, 75, 150, 25, 85, 125, 175, 1, 30, 0 };
    struct tree *t = make_tree(nodes);

    int collector[t->count];
    int k = 0;

    traverse(t->root, &k, collector);

    for (int i = 1; i < t->count; ++i)
        if (collector[i] < collector[i - 1]) {
            printf("0\n");
            return 0;
        }

    printf("1\n");
}

