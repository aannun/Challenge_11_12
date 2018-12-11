CC=clang.exe
#Wall attiva tutti i controlli, Werror trasforma ogni warning in errore
CFLAGS=-Wall -O3 -Wno-pragma-pack -ISDL2-2.0.9\include
LDFLAGS=-lSDL2 -LSDL2-2.0.9\lib\x64

all: orologio.exe

orologio.exe: main.o
	$(CC) $(LDFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $^ 