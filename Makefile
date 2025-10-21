CC=gcc
CFLAGS=-std=c11 -O2 -Wall -Wextra

all: bitcheck

bitcheck: main.o bitboard.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c bitboard.h
	$(CC) $(CFLAGS) -c main.c

bitboard.o: bitboard.c bitboard.h
	$(CC) $(CFLAGS) -c bitboard.c

clean:
	rm -f *.o bitcheck
