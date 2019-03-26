#include <stdio.h>

void main(int argc, char **argv) {
    int nums[] = { 3, 5, 7, 6, 8, 9, 7, 42, 6, 8, 5, 9, 3 };
    int k = 0;

    for (int i = 0; i < sizeof(nums) / sizeof(int); ++i)
        k ^= nums[i];

    printf("%d\n", k);
}

