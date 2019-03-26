#include <stdio.h>

// ( n * (first number + last number) ) / 2

void main(int argc, char **argv) {
    int n = 100, k = 0;
    int nums[n];

    for (int i = 0; i < n; ++i)
        nums[i] = i + 1;

    // "Randomly" reset one of the elements to 0.
    nums[53] = 0;

    for (int i = 0; i < n; ++i)
        k += nums[i];

    int gauss = (n * (n + 1)) / 2;

    printf("%d\n", gauss - k);
}

