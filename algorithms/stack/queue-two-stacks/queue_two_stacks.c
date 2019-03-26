#include "../stack.c"

struct queue {
    struct stack *s1;
    struct stack *s2;
};

void enqueue(struct queue *q, int v) {
    if (size(q->s2) > 0)
        while (size(q->s2))
            push(q->s1, pop(q->s2));

    push(q->s1, v);
}

int dequeue(struct queue *q) {
    if (size(q->s1))
        while (size(q->s1))
            push(q->s2, pop(q->s1));

    return pop(q->s2);
}

int is_empty(struct queue *q) {
    return (size(q->s1) + size(q->s2)) > 0;
}

void main(int argc, char **argv) {
    struct queue *q;

    if (!(q = malloc(sizeof(struct queue)))) {
        fprintf(stderr, "Error: Could not initialize queue");
        exit(1);
    }

    q->s1 = create_stack();
    q->s2 = create_stack();

    enqueue(q, 5);
    enqueue(q, 7);
    enqueue(q, 9);
    enqueue(q, 11);
    printf("%d\n", dequeue(q));
    enqueue(q, 3);

    printf("size s1 -> %d\n", size(q->s1));
    printf("size s2 -> %d\n", size(q->s2));
}

