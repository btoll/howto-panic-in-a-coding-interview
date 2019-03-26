#include <stdio.h>
#include <string.h>

void merge(int nums[], int p, int q, int r) {
    int lowLen = q - p + 1;
    int highLen = r - q;
    int low[lowLen];
    int high[highLen];

    memcpy(low, nums + p, lowLen * sizeof(int));
    memcpy(high, nums + q + 1, highLen * sizeof(int));

    int i = 0, j = 0, k = p;

    while (i < lowLen && j < highLen)
        if (low[i] < high[j])
            nums[k++] = low[i++];
        else
            nums[k++] = high[j++];

    while (i < lowLen)
        nums[k++] = low[i++];

    while (j < highLen)
        nums[k++] = high[j++];
}

void mergesort(int nums[], int p, int r) {
    if (p >= r) return;

    int q = p + r >> 1;

    mergesort(nums, p, q);
    mergesort(nums, q + 1, r);
    merge(nums, p, q, r);
}

void main(int argc, char **argv) {
    int nums[] = { 75, -50, 25, -2000, 50, 0, 5555, -100, 100, -75, -25 };
    int len = sizeof(nums) / sizeof(int);

    mergesort(nums, 0, len);

    for (int i = 0; i < len; ++i)
        printf("%d ", nums[i]);

    printf("\n");
}

