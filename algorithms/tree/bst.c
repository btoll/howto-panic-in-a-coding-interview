#include <stdlib.h>
#include <stdio.h>
#include "bst.h"
#include "stack.c"

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

        while (root) {
            if (v < root->val) {
                if (!root->left) return root->left = new_node;
                else root = root->left;
            } else {
                if (!root->right) return root->right = new_node;
                else root = root->right;
            }
        }

        return root;
    }
}

void inorder(struct tree_node* n) {
//    if (n == NULL) return;
//    inorder(n->left);
//    printf("%d\n", n->val);
//    inorder(n->right);
    if (!n) return;

    struct node *s = create_stack();
    s = push(&s, n);

    while (s != NULL) {
//        while (s) {
            push(&s, n);
            n = n->left;
//        }

        n = pop(&s);
        printf("%d\n", n->val);
        s = push(&s, n);
        n = n->right;
    }

//    const s = [];
//    const v = [];
//    let curr = node;

//    while (curr || s.length) {
//        while (curr) {
//            s.push(curr);
//            curr = curr.left;
//        }
//
//        curr = s.pop();
//        v.push(curr.val);
//        curr = curr.right;
//    }
//
//    return v;
}

