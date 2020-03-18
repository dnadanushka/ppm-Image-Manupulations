#make file - this is the makefile for ppm transform 
CC=gcc  #compiler
CFLAGS  = -Wall -g #flags
TARGET=transform #target file name

all : menu.o print.o parse.o mainDriver.o transform.h
	$(CC) mainDriver.c menu.c print.c parse.c -o $(TARGET)

print.o: print.c transform.h
	$(CC) $(CFLAGS) -c print.c

parse.o: parse.c transform.h
	$(CC) $(CFLAGS) -c parse.c
	
run:
	./transform west_1.ppm

clean:
	rm $(TARGET) *.o output.ppm
