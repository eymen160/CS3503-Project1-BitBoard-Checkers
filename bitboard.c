#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long U64;

#define RED_START    0x00000FFF00000000ULL
#define BLACK_START  0x00000000000FFFULL
#define KING_ROW_RED 0x00000000000000FFULL
#define KING_ROW_BLACK 0xFF00000000000000ULL

U64 red_pieces = RED_START;
U64 black_pieces = BLACK_START;
U64 kings = 0ULL;

void print_board(U64 red, U64 black, U64 kings) {
    printf("\n");
    for (int row = 7; row >= 0; row--) {
        printf("%d ", row + 1);
        for (int col = 0; col < 8; col++) {
            int sq = row * 8 + col;
            U64 mask = 1ULL << sq;
            if (red & mask)
                printf((kings & mask) ? "R " : "r ");
            else if (black & mask)
                printf((kings & mask) ? "B " : "b ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n\n");
}

int valid_move(U64 from_mask, U64 to_mask, U64 player, U64 opponent, int is_red) {
    if (!(player & from_mask)) return 0;
    if ((player & to_mask) || (opponent & to_mask)) return 0;

    int from = __builtin_ctzll(from_mask);
    int to = __builtin_ctzll(to_mask);
    int diff = to - from;

    if (is_red) {
        if (diff == 7 || diff == 9) return 1;
        if (diff == 14 || diff == 18) return 1;
    } else {
        if (diff == -7 || diff == -9) return 1;
        if (diff == -14 || diff == -18) return 1;
    }

    return 0;
}

void move_piece(int from, int to, int is_red) {
    U64 *player = is_red ? &red_pieces : &black_pieces;
    U64 *opponent = is_red ? &black_pieces : &red_pieces;

    U64 from_mask = 1ULL << from;
    U64 to_mask = 1ULL << to;

    if (!valid_move(from_mask, to_mask, *player, *opponent, is_red)) {
        printf("Invalid move.\n");
        return;
    }

    *player &= ~from_mask;
    *player |= to_mask;

    int diff = to - from;
    if (diff == 14 || diff == 18 || diff == -14 || diff == -18) {
        int cap = from + diff / 2;
        U64 cap_mask = 1ULL << cap;
        *opponent &= ~cap_mask;
        kings &= ~cap_mask;
    }

    if (is_red && (to_mask & KING_ROW_BLACK))
        kings |= to_mask;
    else if (!is_red && (to_mask & KING_ROW_RED))
        kings |= to_mask;
}

int check_win(U64 red, U64 black) {
    if (red == 0ULL) return 2;
    if (black == 0ULL) return 1;
    return 0;
}
