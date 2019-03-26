#include <stdio.h>

void main(int argc, char **argv) {
    char *s = argv[1];
    char *t = argv[2];

    while (*s) printf("%c\n", *s++);
    while (*t) printf("%c\n", *t++);
}

