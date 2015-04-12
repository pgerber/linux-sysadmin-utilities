# configuration
CC = gcc
CFLAGS = -std=c99 -pedantic -Wc++-compat -Wall -O3
LDFLAGS =


default: errno
all: default


errno: errno.o
	$(CC) $(LDFLAGS) -o $@ $^

errno.o: errno.c
	$(CC) -c $(CFLAGS) -o $@ $^


clean:
	rm -f errno.o errno
