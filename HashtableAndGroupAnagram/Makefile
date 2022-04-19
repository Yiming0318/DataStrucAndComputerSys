all: run

Main: Hashtable.c Hashtable.h LinkedList.c LinkedList.h ReadFile.c main.c
		gcc -g Hashtable.c LinkedList.c ReadFile.c main.c -o main
run: Main
		./main

### This builds the hashtable library. Change the filenames accordingly. 
Hashtable.o: Hashtable.c Hashtable.h LinkedList.o
	gcc -c -Wall -g Hashtable.c -o Hashtable.o

## Builds the LinkedList library, if you're using it. 
LinkedList.o: LinkedList.c LinkedList.h
	gcc -c -Wall -g LinkedList.c -o LinkedList.o

ReadFile.o: Hashtable.o ReadFile.c
	gcc -c -Wall -g ReadFile.c -o ReadFile.o


## Compiles your hashtable tests.
test.o : ReadFile.o test.c
	gcc -c -Wall -g test.c -o test_hashtable.o

## Puts it all together. 
test: Hashtable.c Hashtable.h LinkedList.c LinkedList.h ReadFile.c test.c 
	gcc -g Hashtable.c LinkedList.c ReadFile.c test.c -o test 
	

clean: 
	rm -rf *~ main
