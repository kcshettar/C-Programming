
all : main.o string.o
	gcc main.o string.o -o main

main.o : main.c  
	gcc -c main.c

string.o : string.h string.c
	gcc  -c string.h string.c 


clean:
	rm *.o main *.gch
