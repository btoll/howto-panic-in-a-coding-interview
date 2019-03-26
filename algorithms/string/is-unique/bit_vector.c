#include <stdlib.h>

int main(int argc, char **argv) {
    char* s = "yellowjacket";
    int v = 0, k = 0;

    while (s[k]) {
        int shift = 1 << s[k++] - 'a';
        if ((v & shift) > 0) return 0;
        v |= shift;
    }

    return 1;
}

