all : main.o string.o status.h
	gcc main.o string.o -o main

main.o : main.c string.h status.h 
	gcc -c main.c

string.o : string.h string.c status.h
	gcc -c string.c 


clean:
	rm *.o main
