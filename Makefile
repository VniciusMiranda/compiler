CC = gcc
CFLAGS =  -g -lfl -Wall -ansi -I src/
LFLAGS = -lm

all: build/goianinha

build/goianinha: build/main.o build/lexico.o build/errors.o
	$(CC) $(CFLAGS) $(LFLAGS) build/lexico.o build/main.o build/errors.o -o build/goianinha

build/errors.o: src/errors.c src/errors.h
	$(CC) $(CFLAGS) -c src/errors.c -o build/errors.o

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/lexico.c: src/goianinha.l src/operations.h src/errors.h src/keywords.h src/types.h
	flex  --yylineno --outfile=build/lexico.c src/goianinha.l

build/lexico.o: build/lexico.c
	$(CC) $(CFLAGS) -c build/lexico.c  -o build/lexico.o

clean:
	rm -rf build/*

