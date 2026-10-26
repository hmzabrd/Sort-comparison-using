CC = gcc
CFLAGS = -std=c11 -O2 -Wall

benchmark: benchmark.o sort.o generate.o
	$(CC) $(CFLAGS) -o benchmark benchmark.o sort.o generate.o

benchmark.o: benchmark.c sort.h generate.h
	$(CC) $(CFLAGS) -c benchmark.c

sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sort.c

generate.o: generate.c generate.h
	$(CC) $(CFLAGS) -c generate.c
