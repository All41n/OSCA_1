CC = gcc
CFLAGS = -c -Wall
LIBDIR = lib
DIST = dist

default: link

link: $(DIST)/main.o $(DIST)/utils.o
	$(CC) $(DIST)/main.o $(DIST)/utils.o -o $(DIST)/simulate

dist/main.o: main.c
	$(CC) $(CFLAGS) main.c -o $(DIST)/main.o

dist/utils.o: $(LIBDIR)/utils.c
	$(CC) $(CFLAGS) $(LIBDIR)/utils.c -o $(DIST)/utils.o

clean:
	rm -rf ./$(DIST) && mkdir $(DIST)