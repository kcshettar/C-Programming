all : main.o string.o vector_string.o array_vector_str.o status.h
	gcc main.o string.o vector_string.o array_vector_str.o -o main -g

main.o : main.c string.h vector_string.h status.h 
	gcc -c main.c -g

string.o : string.h string.c status.h
	gcc -c string.c -g

vector_string.o: vector_string.h vector_string.c string.h 
	gcc -c vector_string.c -g

array_vector_str.o: array_vector_str.h array_vector_str.c string.h vector_string.h
	gcc -c array_vector_str.c -g 

clean:
	rm *.o main *.gch