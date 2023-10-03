CC = g++
CFLAGS = -Wall -O2

all:
	$(CC) $(CFLAGS) -o ./bin/quicknote ./src/main.cpp