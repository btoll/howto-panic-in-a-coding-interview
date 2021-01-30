#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

struct queue* create_queue() {
    struct queue *q;
    if (!(q = (struct queue *) malloc(sizeof(struct queue)))) {
        fprintf(stderr, "Could not allocate memory for new queue!");
        exit(1);
    }
    return q;
}

struct queue_node* create_queue_node(struct tree_node *n) {
    struct queue_node *new_node;
    if (!(new_node = (struct queue_node *) malloc(sizeof(struct queue_node)))) {
        fprintf(stderr, "Could not allocate memory for new node!");
        exit(1);
    }
    new_node->node = n;
    return new_node;
}

struct tree_node* dequeue(struct queue *q) {
    if (q->head == NULL) return NULL;

    struct tree_node *n;

    if (q->head == q->tail) {
        n = q->head->node;
        free(q->head);
        q->head = q->tail = NULL;
    } else {
        n = q->head->node;
//        free(q->head);
        q->head = q->head->next;
    }

    return n;
}

struct queue* enqueue(struct queue *q, struct tree_node *n) {
    struct queue_node* new_node = create_queue_node(n);

    if (q->head == NULL) {
        q->head = q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }

    return q;
}

/*
int peek(struct queue *q) {
    struct tree_node *n = q->head->node;
    return n->val;
}
*/

