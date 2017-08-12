cc = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o

main: $(OBJECTS)
	$(cc) $(CFLAGS) -o main $(OBJECTS)
main.o: main.c
	$(cc) $(CFLAGS) -c main.c -o main.o
clean:
	rm main $(OBJECTS)
