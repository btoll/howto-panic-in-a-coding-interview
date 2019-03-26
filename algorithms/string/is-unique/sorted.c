#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char s[] = "yellowjacket";
    int len = strlen(s);

    if (len > 26) return 0;

    // sort string

    for (int i = 0; i < len; i++)
        if (s[i] == s[i + 1]) return 0;

    return 1;
}

