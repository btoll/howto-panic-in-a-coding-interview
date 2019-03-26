#include "../linked_list.c"

int kth_to_last(struct node **node, int k) {
    struct node *tortoise = *node;
    struct node *hare = (*node)->next;

    int j = 1;

    while (j++ < k && hare->next)
        hare = hare->next;

    if (j - 1 != k) {
        fprintf(stderr, "Error: list length is less than k");
        exit(1);
    }

    while (hare->next) {
        tortoise = tortoise->next;
        hare = hare->next;
    }

    return (*tortoise).val;     // Same as `tortoise->val`.
}

void main(int argc, char **argv) {
    struct node *HEAD = NULL;

    for (int i = 1; i < 10; ++i)
        add(&HEAD, i * 2);

    list(&HEAD);
    printf("\n%d\n", kth_to_last(&HEAD, 3));
}

