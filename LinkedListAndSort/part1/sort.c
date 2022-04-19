#include <stdio.h>

#include "linkedlist.h"

void swap(LinkedListNodePtr first,LinkedListNodePtr second){
	int tmp;
	tmp = first->data; 
	first->data = second -> data;
	second->data = tmp;
}


void insertionSort(LinkedListPtr list) {
	//get first node
    	LinkedListNodePtr front = list->head;
	LinkedListNodePtr back = NULL;
	while (front != NULL){
	//get next node
	back = front->next;
	//update node value when consecutive nodes are not sort
	while(back != NULL && back->prev != NULL && back->data < back->prev->data){
	//swapdata
	swap(back, back->prev);
	//visit to previous node
	back = back->prev;
	}
	//visit to next node
	front = front->next;
	}
}	

