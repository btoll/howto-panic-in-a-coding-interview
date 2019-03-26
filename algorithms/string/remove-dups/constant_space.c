#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void selection_sort(char *s) {
    size_t l = strlen(s);
    for (int i = 0; i < l; ++i)
        for (int j = i + 1; j < l; ++j)
            if (s[i] > s[j]) {
                s[i] = s[i] ^ s[j];
                s[j] = s[i] ^ s[j];
                s[i] = s[i] ^ s[j];
            }
}

void main(int argc, char **argv) {
    char s[] = "wrhelodldl";
    size_t l = sizeof(s) / sizeof(char);

    printf("unsorted -> %s\n", s);
    selection_sort(s);
    printf("  sorted -> %s\n", s);

    int k = 0;
    for (int i = 0; i < l; ++i)
        if (s[i] != s[i + 1]) s[k++] = s[i];

    s[k] = '\0';
    printf(" removed -> %s\n", s);
}

