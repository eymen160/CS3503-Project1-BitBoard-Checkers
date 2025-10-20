#include <stdio.h>
#include "bitboard.c"

int main() {
    printf("\n=== BitBoard Checkers ===\n");
    print_board(red_pieces, black_pieces, kings);

    int from, to;
    int turn = 0;

    while (1) {
        printf("%s's move (from to): ", (turn % 2 == 0) ? "Red" : "Black");
        scanf("%d %d", &from, &to);

        move_piece(from, to, turn % 2 == 0);
        print_board(red_pieces, black_pieces, kings);

        int winner = check_win(red_pieces, black_pieces);
        if (winner == 1) {
            printf("Red wins!\n");
            break;
        } else if (winner == 2) {
            printf("Black wins!\n");
            break;
        }

        turn++;
    }

    return 0;
}
