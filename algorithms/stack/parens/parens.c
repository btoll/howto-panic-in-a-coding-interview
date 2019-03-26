#include "../stack.c"

void main(int argc, char **argv) {
    char *t = "He(ll(o) W)o()r(ld)";
    struct stack *s = create_stack();

    while (*t) {
        if (*t == '(') push(s, *t);

        if (*t == ')')
            if (size(s) == 0) push(s, *t);
            else pop(s);

        *t++;
    }

    printf("%d\n",
        size(s) == 0 ? 1 : 0);
}

