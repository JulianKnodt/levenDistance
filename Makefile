all: dist test

dist: dist.h dist.c
	gcc -Weverything -c dist.c

test: test.c dist.o
	gcc -Weverything -o test test.c dist.o
