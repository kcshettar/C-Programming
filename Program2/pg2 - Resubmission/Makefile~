all : main.o queue.o queue.h
	gcc main.o queue.o -o main

main.o : main.c queue.h queue.h 
	gcc -c main.c

queue.o : queue.h queue.c status.h
	gcc -c queue.c 


clean:
	rm *.o main *.gch
