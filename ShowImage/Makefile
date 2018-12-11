CC=clang.exe
#Wall attiva tutti i controlli, Werror trasforma ogni warning in errore
CFLAGS=-Wall -O3 -Wno-pragma-pack -ISDL2-2.0.9\include
LDFLAGS=-lSDL2 -LSDL2-2.0.9\lib\x64
BINARY=ShowImage
BINARY_TESTS=showImg_tests

ifeq ($(OS),Windows_NT)
	BINARY:=$(BINARY).exe
	BINARY_TESTS:=$(BINARY_TESTS).exe
endif

showImg: main.o 
	$(CC) -o $(BINARY) $(LDFLAGS) $^

main.o: main.c
	$(CC) -c -o $@ $(CFLAGS) $^

tests.o: test.c
	$(CC) -c -o $@ $(CFLAGS) $^

test: test.o tile.o gfx.o
	$(CC) -o $(BINARY_TESTS) $(LDFLAGS) $^
	$(BINARY_TESTS)