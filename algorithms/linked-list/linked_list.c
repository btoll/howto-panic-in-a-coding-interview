#include <stdlib.h>
#include <stdio.h>

struct node {
    struct node *next;
    int val;
};

void add(struct node **head, int v) {
    struct node *n;

    if (!(n = malloc(sizeof(struct node)))) {
        fprintf(stderr, "Could not allocate memory for new node!");
        exit(1);
    }

    if (*head == NULL) {
        n->val = v;
        n->next = NULL;
        *head = n;
    } else {
        struct node *c = *head;

        while (c->next) {
            c = c->next;
        }

        n->val = v;
        n->next = NULL;
        c->next = n;
    }
}

struct node* find(struct node **head, int v) {
    if (*head == NULL) return NULL;
    if ((*head)->val == v) return *head;

    struct node *n = (*head)->next;

    while (n) {
        if (n->val == v) return n;
        n = n->next;
    }

    return NULL;
}

void list(struct node **head) {
    struct node *n = *head;

    while (n) {
        printf("%d\n", n->val);
        n = n->next;
    }
}

