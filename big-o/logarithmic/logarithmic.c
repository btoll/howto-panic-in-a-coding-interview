#include <stdio.h>

int binary_search(int nodes[], int p, int r, int k) {
    if (p > r)
        return -1;

    int q = p + r >> 1;

    if (nodes[q] == k)
        return q;

    if (nodes[q] > k)
        binary_search(nodes, p, q - 1, k);
    else
        binary_search(nodes, q + 1, r, k);
}

int main(int argc, char **argv) {
    int nodes[] = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45};

    printf("%d\n",
        binary_search(nodes, 0, sizeof(nodes) / sizeof(int), 15));
}

