###
## Makefile
## INFO0947: Projet 1
## authors: SALEHIKATOZI SeyedPouria S192865 
## groupe : 4
## date: 9/07/2021
##
###

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes
LD=gcc
LDFLAGS=

# Files
EXEC=multiplicite
MODULES=main-multiplicite.c multiplicite.c
OBJECTS=main-multiplicite.o multiplicite.o

## Rules

all: $(EXEC)

multiplicite: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

main-multiplicite.o: main-multiplicite.c
	$(CC) -c main-multiplicite.c -o main-multiplicite.o $(CFLAGS)

multiplicite.o: multiplicite.c
	$(CC) -c multiplicite.c -o multiplicite.o $(CFLAGS)

clean:
	rm -f *.o $(EXEC) *~
