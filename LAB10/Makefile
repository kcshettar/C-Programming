CC = gcc
CFLAGS = -Wall -W
DBGFLAG = -g -DDEBUG

all : main.o string.o vector_string.o array_vector_str.o status.h
	$(CC) main.o string.o vector_string.o array_vector_str.o -o main

main.o : main.c string.h vector_string.h status.h 
	$(CC) -c main.c

string.o : string.h string.c status.h
	$(CC) -c string.c

vector_string.o: vector_string.h vector_string.c string.h 
	$(CC) -c vector_string.c

array_vector_str.o: array_vector_str.h array_vector_str.c string.h vector_string.h
	$(CC) -c array_vector_str.c

debug : main.o string.o vector_string.o array_vector_str.o status.h
	$(CC) $(DBGFLAG) main.o string.o vector_string.o array_vector_str.o -o main

clean:
	rm *.o main