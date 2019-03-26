#include "../linked_list.c"

void main(int argc, char **argv) {
    struct node *HEAD = NULL;

    for (int i = 1; i < 10; ++i)
        add(&HEAD, i * 2);

    struct node *to_delete = find(&HEAD, 10);

    if (to_delete->next) {
        to_delete->val = to_delete->next->val;
        to_delete->next = to_delete->next->next;
    } else {
        fprintf(stderr, "Can't delete tail!");
        exit(1);
    }
}

