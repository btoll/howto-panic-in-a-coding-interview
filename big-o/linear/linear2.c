#include <stdio.h>

size_t len(char* s) {
    size_t k = 0;
    while (*(s++)) k++;
    return k;
}

void rot3(char* s) {
    for (int i = 0; i < len(s); i++) {
        char c = s[i];

        if (c >= 'a' && c <= 'z')
            s[i] = ((c + 3 - 'a') % 26) + 'a';
    }
}

void main(int argc, char **argv) {
    char s[] = "pq!rst uvwxyz_abc";

    rot3(s);
    int k = 0;

    while (*(s + k)) {
        printf("%c", *(s + k++));
    }
}

