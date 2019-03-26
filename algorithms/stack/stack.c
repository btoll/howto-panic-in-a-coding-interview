#include <stdlib.h>
#include <stdio.h>

#define MAX_N    100

struct stack {
    int data[MAX_N];
    int sp;     // stack pointer
};

struct stack* create_stack() {
    struct stack *s;

    if (!(s = malloc(sizeof(struct stack)))) {
        fprintf(stderr, "Error: Could not initialize stack");
        exit(1);
    }

    return s;
}

int pop(struct stack *s) {
    if (s->sp > 0)
        return s->data[--s->sp];
    else
        fprintf(stderr, "Error: Stack empty");
}

void push(struct stack *s, int v) {
    if (s->sp < MAX_N)
        s->data[s->sp++] = v;
    else
        fprintf(stderr, "Error: Stack full");
}

int size(struct stack *s) {
    return s->sp;
}

