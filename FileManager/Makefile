CC=clang.exe
#Wall attiva tutti i controlli, Werror trasforma ogni warning in errore
CFLAGS=-Wall -O3
LDFLAGS=-L. -llibui
BINARY=orologio
BINARY_TESTS=orologio_tests

ifeq ($(OS),Windows_NT)
	BINARY:=$(BINARY).exe
	BINARY_TESTS:=$(BINARY_TESTS).exe
endif

main.exe: main.o
	$(CC) $(LDFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $^ 

tests.o: test.c
	$(CC) -c -o $@ $(CFLAGS) $^

test: test.o
	$(CC) -o $(BINARY_TESTS) $(LDFLAGS) $^
	$(BINARY_TESTS)