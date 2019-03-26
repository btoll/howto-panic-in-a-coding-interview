#include <stdlib.h>
#include <stdio.h>
#include "tic_tac_toe.h"

// Ideas for improvement:
// 1. Right now plays are zero-based, change to {1-9}.
// 2. Warn when a play has already been made.
// 3. Doesn't handle stalemates.
// 4. Other?

int winners[] = {
    // Across.
    7, 56, 448,

    // Down.
    73,
    146,
    292,

    // Diagonal.
    273,
        84
};

void clear() {
    // Clear screen.
    // https://stackoverflow.com/a/7660837
    printf("\e[1;1H\e[2J");
}

void draw_board(short x, short o) {
    clear();

    for (int i = 0, row = 3; i < row; ++i) {
        for (int j = 0, k = i * row; j < row; ++j, ++k) {
            if ((o & (1 << k)) > 0) printf("%c ", 'O');
            else if ((x & (1 << k)) > 0) printf("%c ", 'X');
            else printf("%c ", '+');
        }

        printf("\n");
    }
}

short is_winner(int *winners, short *x, short *o) {
    short k = 0;
    char winner = '\0';

    while (*(winners + k)) {
        int w = *(winners + k);

        if ((w & *x) == w) {
            winner = 'X';
            break;
        }

        if ((w & *o) == w) {
            winner = 'O';
            break;
        }

        k++;
    }

    if (winner) {
        char buf[2];

        printf("\nWe have a winner [%c]!\n", winner);
        printf("Play again [y/N]?");
        fgets(buf, 3, stdin);

        if (*buf == 'y') {
            *x = *o = 0;
            draw_board(*x, *o);
        } else return 1;
    }

    return 0;
}

void play(short player, short *x, short *o) {
    char buf[2];

    printf("Your play [%c]: ", player % 2 ? 'X' : 'O');
    fgets(buf, 3, stdin);

    int move = atoi(buf);

    if (player % 2) {
        if ((*x & (1 << move)) == 0)
            *x |= 1 << move;
    } else {
        if ((*o & (1 << move)) == 0)
            *o |= 1 << move;
    }
}

void main(int argc, char **argv) {
    short x = 0, o = 0, player = 0, kill = 0;

    while (!kill) {
        play(player, &x, &o);
        draw_board(x, o);
        kill = is_winner(winners, &x, &o);
        player++;
    }
}

