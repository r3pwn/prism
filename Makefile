CC=mpicc
CFLAGS=-I.

all: main.o
    $(CC) -o prism main.o
	
clean:
    rm -f prism *.o *.out