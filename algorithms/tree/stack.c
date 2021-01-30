#include <stdlib.h>
#include <stdio.h>

struct node {
    struct node *next;
    struct tree_node *tn;
};

struct node* create_stack() {
    struct node *n;
    if (!(n = (struct node *) malloc(sizeof(struct node)))) {
        fprintf(stderr, "Could not allocate memory for new queue!");
        exit(1);
    }
    return n;
}

struct tree_node *pop(struct node **head) {
    struct tree_node *k;

    if (*head == NULL) {
        return NULL;
    } else {
        k = (*head)->tn;
        *head = (*head)->next;
    }

    return k;
}

struct node *push(struct node **head, struct tree_node *tn) {
    struct node *n;

    if (!(n = (struct node *) malloc(sizeof(struct node)))) {
        fprintf(stderr, "Could not allocate memory for new node!");
        exit(1);
    }

    if (*head == NULL) {
        n->tn = tn;
        n->next = NULL;
        *head = n;
    } else {
        n->tn = tn;
        n->next = *head;
        *head = n;
    }

    return *head;
}

