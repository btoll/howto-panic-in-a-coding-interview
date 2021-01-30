#include "../bst.c"

int main(int argc, char **argv) {
    int nodes [] = { 100, 150, 50, 25, 75, 125, 175, 15, 30, 0 };
    struct tree *t = make_tree(nodes);
    inorder(t->root);
}

