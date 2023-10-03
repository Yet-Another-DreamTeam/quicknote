CC = g++
CFLAGS = -std=c++17 -Wall -O2 -static -static-libgcc -static-libstdc++

all:
	$(CC) $(CFLAGS) -o ./bin/quicknote ./src/main.cpp

clean:
	rm -rf ./bin/quicknote

install:
	cp ./bin/quicknote /usr/local/bin/quicknote	
