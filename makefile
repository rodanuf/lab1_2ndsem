CC = gcc
head := $(wildcard *.h)

all: main.exe

main.exe: matrix.o lab.o functions.o
	CC matrix.o lab.o functions.o -o main.exe
clean:
	rm -f *.o *.exe
%.o : %.c $(head) 
	CC -c $< -o $@
