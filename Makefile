CC=gcc
CFLAGS=-I. -Wall

all: libvector.a

vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -O -c vector.c
libvector.a: vector.o
	ar rcs libvector.a vector.o

.PHONY: clean

clean:
	$(RM) *.o *.a *.gch
