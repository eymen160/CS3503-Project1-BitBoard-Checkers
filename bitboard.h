#ifndef BITBOARD_H
#define BITBOARD_H
#include <stdint.h>

typedef unsigned long long U64;

extern U64 RED, BLACK, KINGS;
extern int TURN_RED; /* 1 = red, 0 = black */

static inline U64 bit(int s){ return 1ULL<<s; }
static inline int  getb(U64 b,int s){ return (b>>s)&1ULL; }
static inline void setb(U64* b,int s){ *b |= bit(s); }
static inline void clrb(U64* b,int s){ *b &= ~bit(s); }
static inline void togg(U64* b,int s){ *b ^= bit(s); }
static inline int  popc(U64 b){ return __builtin_popcountll(b); }

void init_board(void);
void print_board(void);
int  move_piece(int from,int to);
int  has_capture_from(int from);
int  save_game(const char* path);
int  load_game(const char* path);
int  winner(void);

#endif
