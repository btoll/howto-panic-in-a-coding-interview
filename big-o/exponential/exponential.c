#include <stdio.h>

unsigned long fibonacci(int n) {
    if (n < 2) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void main(int argc, char **argv) {
    for (int i = 1; i <= 0x14; ++i)
        printf("%ld\n", fibonacci(i));
}

