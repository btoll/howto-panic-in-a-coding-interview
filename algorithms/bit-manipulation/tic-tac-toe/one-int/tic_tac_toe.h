/*************************
    // Powers of two.

    // Across.
    1, 2, 4
    8, 16, 32
    64, 128, 256

    // Down.
    1, 8, 64
    2, 16, 128
    4, 32, 256

    // Diagonal.
    1, 16, 256
    4, 16, 64

    -------------------

    // Left shifts.

    // Down.
    0, 1, 2
    3, 4, 5
    6, 7, 8

    // Down.
    0, 3, 6
    1, 4, 7
    2, 5, 8

    // Diagonal.
    0, 4, 8
    2, 4, 6
**************************/

void clear();
void draw_board(int state);
short is_winner(int *winners, int *state);
void play(short player, int *state);

