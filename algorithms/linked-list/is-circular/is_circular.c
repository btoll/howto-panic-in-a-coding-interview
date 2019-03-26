#include "../linked_list.c"

int is_circular(struct node **node) {
    struct node *tortoise = *node;
    struct node *hare = *node;
    int i = 0;

    while (i++ < 2 && hare->next)
        hare = hare->next;

    while (tortoise->next && hare->next) {
        tortoise = tortoise->next;
        hare = hare->next;

        if (tortoise == hare) return 1;
        if (hare->next) hare = hare->next;
    }

    return 0;
}

void main(int argc, char **argv) {
    struct node *HEAD = NULL;

    for (int i = 1; i < 10; ++i)
        add(&HEAD, i * 2);

    list(&HEAD);

    struct node *tail = find(&HEAD, 18);
    tail->next = HEAD;

    printf("%d\n", is_circular(&HEAD));
}

