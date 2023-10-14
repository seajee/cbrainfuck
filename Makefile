
CC=gcc
CFLAGS=-Wall -Wextra
SRC=src/main.c src/util.c
OUT_DIR=build/cbf

main:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT_DIR)
