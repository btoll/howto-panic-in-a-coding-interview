#include <stdlib.h>
#include <stdio.h>

// for n in {1..64}; do echo -n $n " -> " ; ./a.out $n; done

int is_power_of_two(int v) {
    if (v == 1) return 1;

    do {
        if (v & 1 != 0) return 0;
    } while ((v >>= 1) > 1);

    return 1;
}

void main(int argc, char **argv) {
    printf("%d\n",
            is_power_of_two(atoi(argv[1])));
}

