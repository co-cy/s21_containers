CC=g++
SRC=
OBJ=
CFLAGS= -g -Wall -Werror -Wextra -std=c++17
TESTFLAGS=-lgtest

test: 
	$(CC) $(CFLAGS) tests/tree_tests.cc -o test.out $(TESTFLAGS)
	./test.out
	rm test.out

clean:
	rm test.out
