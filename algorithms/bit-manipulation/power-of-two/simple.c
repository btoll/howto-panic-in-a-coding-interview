#include <stdlib.h>
#include <stdio.h>

// for n in {1..64}; do echo -n $n " -> " ; ./a.out $n; done

void main(int argc, char **argv) {
    int v = atoi(argv[1]);
    printf("%d\n",
            (v & (v - 1)) == 0);
}

