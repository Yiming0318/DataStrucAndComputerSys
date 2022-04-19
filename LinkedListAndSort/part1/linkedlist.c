#include <stdio.h>
#include "linkedlist.h"

// ======================================================
// LinkedList: A Doubly-Linked List 
// ======================================================

// Creates a LinkedList.
// The customer is responsible for calling DestroyLinkedList()
// to destroy the LinkedList when done.
//
// Returns a LinkedList; NULL if there's an error. 
LinkedListPtr CreateLinkedList(){
//	LinkedListPtr newList = (LinkedListPtr)malloc(sizeof(LinkedListPtr));
	LinkedListPtr newList = (LinkedListPtr)malloc(28);//20
	if(newList == NULL){
		return NULL;
	}
	newList -> head = NULL;
	newList -> tail = NULL;
	newList -> num_elements = 0;
	return newList;
}

// Destroys a LinkedList.
// All structs associated with a LinkedList will be
// released and freed.
//
// INPUT: A pointer to a LinkedList.
void DestroyLinkedList(LinkedListPtr list){
	//if list is NULL, do nothing
	if(list == NULL){
		return;
	}
	LinkedListNodePtr currentNode = list -> head; //define current Node
	while(currentNode != NULL){
		LinkedListNodePtr temp = currentNode;//store currentNode
		//move to next Node
		currentNode = currentNode -> next;
		//free the storing currentNode which is the previous one
		free(temp);
	} //end the while loop when currentNode touch the NULL tail
	free(list);
}

// Returns the number of elements in the linked list. 
// 
// INPUT: A LinkedList 
// 
// Returns the number of elements in the list. 
unsigned int NumElementsInLinkedList(LinkedListPtr list){
	return list -> num_elements;
	
}
// Adds an element to the head of a LinkedList, with the given value
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure. 
int InsertLinkedList(LinkedListPtr list, int data){
	LinkedListNode* node = CreateLinkedListNode(data);
	//if the head is not NULL, newnode will point to the head, 
	//and the head will become the new node
	if(list->head != NULL){
	node->next = list->head;
	list->head->prev = node;
	list->head = node;
	}
	//if empty
	if(list->head == NULL && list->tail == NULL){
		list->head = node;
		list->tail = node;
	}
	list->num_elements ++;	 
	return 0;
}


// Adds an element to the tail of a LinkedList, with the given value.
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure. 
int AppendLinkedList(LinkedListPtr list, int data){
	LinkedListNode* node = CreateLinkedListNode(data);
        
        if(list->head == NULL){
                list->head = node;
                list->tail = node;
		list->num_elements ++;
		return 0;
		}
	
	list->tail->next = node;
        node->prev = list ->tail;
        list->tail = node;
	
	
	list->num_elements ++;
	return 0;       
}

// Prints out the given LinkedListPtr. 
//
// INPUT: A pointer to the LinkedList that will be printed out.
//
// Returns 0 if the insertion was successful; non-zero for failure. 
int PrintLinkedList(LinkedListPtr list){
	if(list == NULL){
		return 1;
	}	
	LinkedListNodePtr currentNode = list->head;
	while(currentNode != NULL){
		printf("%d ",currentNode -> data);
		currentNode = currentNode -> next; //move to next node
	}
	return 0;
}

// Creates a LinkedListNode by malloc'ing the space.
//
// INPUT: A pointer that the payload of the returned LLNode will point to.
//
// Returns a pointer to the new LinkedListNode.
LinkedListNode* CreateLinkedListNode(int data){
	//LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	LinkedListNode* newNode = (LinkedListNode*)malloc(24);//16
	if(newNode == NULL){
		return NULL;
	}
	newNode -> data = data;
	newNode -> next = NULL;
	newNode -> prev = NULL;
	return newNode;
}

// Destroys and free's a provided LLNode.
//
// INPUT: A pointer to the node to destroy.
//
// Returns 0 if the destroy was successful.
int DestroyLinkedListNode(LinkedListNode *node){
	if(node == NULL){
		return 1;
	}
	free(node);
	return 0;
}
// Removes a given element from a linkedList.
//
// INPUT: A pointer to a linked list.
// INPUT: A ListNodePtr that points to a LLNode to be removed from the list.
//
// Returns 0 if the destroy was successful
//   (primarily that the provide Ptr is in the list and could be free'd).
int RemoveLLElem(LinkedListPtr list, LinkedListNodePtr ptr){
	if(list == NULL){
		return 1;
	}
	if(ptr == NULL){
		return 1;
	}
	LinkedListNodePtr curr = list->head;
	while(curr != NULL && curr != ptr){//traversal to find the node needing removement
		curr = curr -> next;
	}
	if(curr != NULL){ //find the node needing removement
		if(list->head == curr){//if node to be deleted is head node
			list->head = curr->next;
		}
		if(curr->next != NULL){//change next only del node next is not NULL
			curr->next->prev = curr->prev;
		}
		if(curr->prev != NULL){//change prev only del node prev is not NULL
			curr->prev->next = curr->next;
		}
	}else{//not find the del node
	return 1;
	}
	free(curr);
	return 0;
}
