#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
LinkedListNode* CreateLinkedListNode(void* data) {
    LinkedListNodePtr node = (LinkedListNodePtr)malloc(sizeof(LinkedListNode));
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}


int DestroyLinkedListNode(LinkedListNode *node) {
    if (node == NULL) {
        return 1;
    }
    free(node->data);
    free(node);
    return 0;
}

LinkedList CreateLinkedList() {
    LinkedList newList = (LinkedList)malloc(sizeof(struct ll_head));
    if (newList == NULL) {
        return NULL;
    }
    newList -> head = NULL;
    newList -> tail = NULL;
    newList -> num_elements = 0;
    return newList;
}

int DestroyLinkedList(LinkedList list) {
    // if list is NULL, do nothing
    if (list == NULL) {
        return 1;
    }
    LinkedListNodePtr currentNode = list -> head;  // define current Node
    while (currentNode != NULL) {
        LinkedListNodePtr temp = currentNode;  // store currentNode
        // move to next Node
        currentNode = currentNode -> next;
        // free the storing currentNode which is the previous one
        free(temp);
    }  // end the while loop when currentNode touch the NULL tail
    free(list);
    return 0;
}

int InsertLinkedList(LinkedList list, void* data) {
    LinkedListNode* node = CreateLinkedListNode(data);
    // if the head is not NULL, newnode will point to the head,
    // and the head will become the new node
    if (list->head != NULL) {
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
    }
    // if empty
    if (list->head == NULL && list->tail == NULL) {
        list->head = node;
        list->tail = node;
    }
    list->num_elements++;
    return 0;
}

int NumElemsInLinkedList(LinkedList list) { return list->num_elements; }

//  int main(){
//   return 1;
//  }

