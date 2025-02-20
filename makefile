CC = gcc
head := $(wildcard *.h)

all: main.exe

main.exe: matrix.o main.o functions.o
	CC matrix.o main.o functions.o -o main.exe
clean:
	rm -f *.o *.exe
%.o : %.c $(head) 
	CC -c $< -o $@
