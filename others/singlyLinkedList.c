#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node* next;
}node_t;



typedef struct slist{
	node_t* head;
	node_t* tail;
	int size;

}slist_t;

node_t* makeSList(){
        slist_t* newList = (slist_t*)malloc(sizeof(slist_t));
        if (newList != NULL){
                return;
        }
        newList->head = NULL;
	newList->tail = NULL;
	newList->size = 0;
}
	

int push_front(slist_t* slist, int value){
	if (slist == NULL){
		return 0;
	}
	node_t* newNode = makeNode(value);
	if(newNode == NULL){
		return 0;
	}

	//1. if the head and tail are both NULL
	//2. if the head is not NULL, newnode will point to the head, 
	//and the head will become the new node
}






//lets see what happens when node is node1(from main)
void print(node_t* node){

	node_t* itr = node; //itr = &node1
	while( itr != NULL){
		printf("%d", itr ->data);
		itr = itr->next;//itr = (&node1)->next
	}	
	printf("\n");
}


node_t* makeNode(int data){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	if (newNode == NULL){
		return NULL;
	}
	newNode->data = data;
	return newNode;	
}


void freeNode(node_t* node){
	if (node == NULL){
		return;
	}
	free(node);
}





int main(){
	node_t* node1 = makeNode(1);
	node_t* node2 = makeNode(2);
	node_t* node3 = makeNode(3);
	
	
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	
	print(node1);
	freeNode(node1);
	freeNode(node2);
	freeNode(node3);

	return 0;
}
