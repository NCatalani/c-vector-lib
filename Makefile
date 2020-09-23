CC=gcc
CFLAGS=-I. -Wall
DEPS = vector.h
OBJ = vector.o main.o 
TARGET = main

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	$(RM) $(TARGET) *.o
