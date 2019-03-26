#include <stdlib.h>
#include <stdio.h>

void main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <n>\n", argv[0]);
        exit(1);
    }

    int n = atoi(argv[1]);
    int matrix[n][n];
    int k = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = k++;

    printf("Created %dx%d matrix!\n", n, n);
}

