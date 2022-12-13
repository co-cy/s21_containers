CC=g++
SRC=
OBJ=
CFLAGS= -Wall -Wextra -std=c++17 -g
TESTFLAGS=-lgtest -lgtest_main

test: 
	$(CC) $(CFLAGS) tests/tree_tests.cc -o test.out $(TESTFLAGS)
	./test.out
	rm test.out

clean:
	rm test.out

my_main:
	g++ -std=c++17 main.cc -g -o my_test
	./my_test