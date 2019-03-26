#include <stdlib.h>
#include <stdio.h>

void rot3(char* s) {
    int k = 0;

    while (*(s + k)) {
        char c = *(s + k);

        if (c >= 'a' && c <= 'z')
            *(s + k) = ((c + 3 - 'a') % 26) + 'a';

        k++;
    }
}

void main(int argc, char** argv) {
    if (argc == 1) {
        printf("Usage: %s <string>\n", argv[0]);
        exit(1);
    }

    char *s = argv[1];
    rot3(s);
    printf("%s\n", s);
}

