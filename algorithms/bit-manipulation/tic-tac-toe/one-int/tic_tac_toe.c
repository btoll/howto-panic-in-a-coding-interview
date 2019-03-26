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

void draw_board(int state) {
    clear();

    short x = state;
    short o = state >> 16;

    for (int i = 0, row = 3; i < row; ++i) {
        for (int j = 0, k = i * row; j < row; ++j, ++k) {
            if ((o & (1 << k)) > 0) printf("%c ", 'O');
            else if ((x & (1 << k)) > 0) printf("%c ", 'X');
            else printf("%c ", '+');
        }

        printf("\n");
    }
}

short is_winner(int *winners, int *state) {
    short k = 0;
    char winner = '\0';

    short x = *state;
    short o = *state >> 16;

    while (*(winners + k)) {
        int w = *(winners + k);

        if ((w & x) == w) {
            winner = 'X';
            break;
        }

        if ((w & o) == w) {
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
            *state = 0;
            draw_board(*state);
        } else return 1;
    }

    return 0;
}

void play(short player, int *state) {
    char buf[2];

    printf("Your play [%c]: ", player % 2 ? 'X' : 'O');
    fgets(buf, 3, stdin);

    int move = atoi(buf);

    if (player % 2) {
        if ((*state & (1 << move)) == 0)
            *state |= 1 << move;
    } else {
        short o = *state >> 16;

        if ((o & (1 << move)) == 0) {
            o |= 1 << move;
            *state |= o << 16;
        }
    }
}

void main(int argc, char **argv) {
    short player = 0, kill = 0;
    int state = 0;

    while (!kill) {
        play(player, &state);
        draw_board(state);
        kill = is_winner(winners, &state);
        player++;
    }
}

