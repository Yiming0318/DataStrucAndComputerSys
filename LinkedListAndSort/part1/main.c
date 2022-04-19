#include <stdio.h>
#include "sort.h"
#include "linkedlist.h"
#include <stdlib.h>
#include <time.h>

int main() {
	const int MIN = -30;
 	const int MAX = 30;
  	const int HALF = 25;
 
  	srand(27);
 	LinkedListPtr list = CreateLinkedList();
	
	int i; 
  	for (i = 0; i < HALF ; i++){
  		int randomNumber =  MIN + (rand() % (MAX - MIN));
     		AppendLinkedList(list, randomNumber);
     		InsertLinkedList(list,randomNumber);
  	}
	printf("size of linkedlist is %d\n",NumElementsInLinkedList(list));
	printf("presorted list is ");
	PrintLinkedList(list);
	printf("\n");
	printf("After Insertion Sort \n");
	printf("postsorted list is ");
	insertionSort(list);
	PrintLinkedList(list);
        printf("\n");
	DestroyLinkedList(list);
	return 0;
}
