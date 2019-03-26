#include <stdlib.h>
#include <stdio.h>

void main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <value> <high bit> <low bit>\n", argv[0]);
        exit(1);
    }

    // Create mask between bits j and k, inclusive.
    int v = atoi(argv[1]);
    int j = atoi(argv[2]);
    int k = atoi(argv[3]);

    int left = ~0 << j;
    int right = (1 << k) - 1;
    int mask = ~(left | right);
    int res = mask & v;

    printf("  mask -> %d\n", mask);
    printf("result -> %d\n", res);
}

