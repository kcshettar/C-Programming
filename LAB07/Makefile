all : main.o string.o vector_string.o status.h
	gcc main.o string.o vector_string.o -o main

main.o : main.c string.h vector_string.h status.h 
	gcc -c main.c

vector_string.o: vector_string.c vector_string.h string.h 
	gcc -c vector_string.c

string.o : string.h string.c status.h
	gcc -c string.c 

clean:
	rm *.o main *.gch