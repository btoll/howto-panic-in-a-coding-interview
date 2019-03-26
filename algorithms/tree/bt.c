#include <stdlib.h>
#include <stdio.h>
#include "bt.h"
#include "queue.c"

struct tree *make_tree(int *nodes) {
    struct tree *t;

    if ((t = (struct tree *) malloc(sizeof(struct tree))) == NULL) {
        fprintf(stderr, "Could not allocate memory for new tree!");
        exit(1);
    }

    t->root = add(NULL, *nodes++);
    while (*nodes)
        add(t->root, *nodes++);

    return t;
}

struct tree_node* create_tree_node(int v) {
    struct tree_node *new_node;
    if (!(new_node = (struct tree_node *) malloc(sizeof(struct tree_node)))) {
        fprintf(stderr, "Could not allocate memory for new node!");
        exit(1);
    }

    new_node->val = v;
    return new_node;
}

struct tree_node* add(struct tree_node *root, int v) {
    if (root == NULL) {
        return create_tree_node(v);
    } else {
        struct tree_node* new_node = create_tree_node(v);
        struct queue *q = create_queue();
        enqueue(q, root);

        while (q->head) {
            struct tree_node *p = dequeue(q);

            if (p->left == NULL) {
                p->left = new_node;
                return new_node;
            } else if (p->right == NULL) {
                p->right = new_node;
                return new_node;
            }

            if (p->left) q = enqueue(q, p->left);
            if (p->right) q = enqueue(q, p->right);
        }

        return root;
    }
}

void preorder(struct tree_node* n) {
    if (n == NULL) return;
    printf("%d\n", n->val);
    preorder(n->left);
    preorder(n->right);
}

void inorder(struct tree_node* n) {
    if (n == NULL) return;
    inorder(n->left);
    printf("%d\n", n->val);
    inorder(n->right);
}

void postorder(struct tree_node* n) {
    if (n == NULL) return;
    postorder(n->left);
    postorder(n->right);
    printf("%d\n", n->val);
}

