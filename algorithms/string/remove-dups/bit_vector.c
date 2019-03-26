#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(int argc, char **argv) {
    char s[] = "hwwrhelodldl";
    int v = 0, k = 0;

    printf("%s\n", s);

    for (int i = 0; i < strlen(s); ++i) {
        int shifted = 1 << s[i] - 'a';

        if ((v & shifted) == 0) {
            v |= shifted;
            s[k++] = s[i];
        }
    }

    s[k] = '\0';
    printf("%s\n", s);
}

