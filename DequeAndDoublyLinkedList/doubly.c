#include <stdio.h>
#include "doubly.h"
// ======================================================
// LinkedList: A Doubly-Linked List
// ======================================================

// Creates a LinkedList.
// The customer is responsible for calling DestroyLinkedList()
// to destroy the LinkedList when done.
//
// Returns a LinkedList; NULL if there's an error.
LinkedListPtr CreateLinkedList() {
// LinkedListPtr newList = (LinkedListPtr)malloc(sizeof(LinkedListPtr));
    LinkedListPtr newList = (LinkedListPtr)malloc(28);  // 20
    if (newList == NULL) {
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
void DestroyLinkedList(LinkedListPtr list) {
    // if list is NULL, do nothing
    if (list == NULL) {
        return;
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
}

// Returns the number of elements in the linked list.
//
// INPUT: A LinkedList
//
// Returns the number of elements in the list.
unsigned int NumElementsInLinkedList(LinkedListPtr list) {
    return list -> num_elements;
}


// Adds an element to the left of a LinkedList, with the given value
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int addLeft(LinkedListPtr list, int data) {
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

// Adds an element to the tail of a LinkedList, with the given value.
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int addRight(LinkedListPtr list, int data) {
    LinkedListNode* node = CreateLinkedListNode(data);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        list->num_elements++;
        return 0;
    }
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
    list->num_elements++;
    return 0;
}

// Remove a node at given index in the linked list
//
// INPUT: A pointer to a linked list
// INPUT: The index number, integer
// INPUT: A value for a node
// Returns 0 if success otherwise 1
int insertAt(LinkedListPtr list, int index, int data) {
    if (list == NULL) {
        return 1;
    }
    if (index < 0) {
        return 1;
    } else if (index == 0) {  // add at left
        addLeft(list, data);
    } else if (index == NumElementsInLinkedList(list) - 1) {  // add at right
        addRight(list, data);
    } else if (index > NumElementsInLinkedList(list) - 1) {
        return 1;
    } else {
    // find the index node position first
        LinkedListNodePtr curr = list->head;
        while (index > 0) {
            curr = curr->next;
            index -= 1;
        }
        // create the new node to insert
        LinkedListNode* node = CreateLinkedListNode(data);
        // insert the new node between curr and curr.prev
        // eg 1 <-> 2 <-> 3 <-> 4, index = 1, curr = node(2), new node = node(0)
        // we insert node 0 between curr which is node(2) and prev is node(1)
        // 1 <-> 0 <-> 2 <-> 3 <-> 4
        node->next = curr;
        curr->prev->next = node;
        node->prev = curr->prev;
        curr->prev = node;
        list->num_elements++;
        return 0;
    }
}


// Creates a LinkedListNode by malloc'ing the space.
//
// INPUT: A pointer that the payload of the returned LLNode will point to.
//
// Returns a pointer to the new LinkedListNode.
LinkedListNode* CreateLinkedListNode(int data) {
// LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    LinkedListNode* newNode = (LinkedListNode*)malloc(24);  // 16
    if (newNode == NULL) {
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
int DestroyLinkedListNode(LinkedListNode *node) {
    if (node == NULL) {
        return 1;
    }
    free(node);
    return 0;
}

// Print out given linked list
//
// INPUT: A pointer to the LinkedList that will be printed out.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int PrintLinkedList(LinkedListPtr list) {
    if (list == NULL) {
        return 1;
    }
    LinkedListNodePtr currentNode = list->head;
    while (currentNode != NULL) {
        printf("%d ", currentNode -> data);
        currentNode = currentNode -> next;  // move to next node
    }
    return 0;
}

// Remove a node at given index in the linked list
//
// INPUT: A pointer to a linked list
// INPUT: The index number, integer
// Returns 0 if success otherwise 1
int removeAt(LinkedListPtr list, int index) {
    if (list == NULL) {
        return 1;
    }
    if (index < 0) {
        return 1;
    }
    LinkedListNodePtr curr = list->head;
    while (index > 0) {  // find the removed node
        if (curr != NULL) {
            curr = curr->next;
            index -= 1;
        } else {  // out of range
            return 1;
        }
    }
    if (list->head == curr) {  // if node to be deleted is head node
            list->head = curr->next;
        }
        if (curr->next != NULL) {  // change next only del node next is not NULL
            curr->next->prev = curr->prev;
        }
        if (curr->prev != NULL) {  // change prev only del node prev is not NULL
            curr->prev->next = curr->next;
        }
    free(curr);
    list->num_elements--;
    return 0;
}

// Remove the head node in the linked list
//
// INPUT: A pointer to a linked list
// Returns 1 for failure otherwise 0
int removeLeft(LinkedListPtr list) {
    removeAt(list, 0);  // 0 is the head index.
}


// Remove the tail node in the linked list
//
// INPUT: A pointer to a linked list
// Returns 1 for failure otherwise 0
int removeRight(LinkedListPtr list) {
    int index;
    index = NumElementsInLinkedList(list) - 1;  // tail_index = length - 1
    removeAt(list, index);
}

// Determine whether the given linked list has the provided value
//
// INPUT: A pointer to a linked list
// INPUT: The checked data value
// Returns 1 if it has the value, 0 it does not has the value
int hasValue(LinkedListPtr list, int value) {
    //  check the invalid case
    if (list == NULL) {
        return 1;
    }
    // traversal the linked list to search the value
    LinkedListNodePtr curr = list->head;
    // traversal to find the node needing removement
    while (curr != NULL && curr->data != value) {
        curr = curr -> next;
    }
    if (curr != NULL) {  // get the value!
        return 1;
    }
    // not find the value
    return 0;
}

int main() {
    LinkedListPtr list = CreateLinkedList();
    printf("addLeft node 1 to the empty list \n");
    addLeft(list, 1);
    PrintLinkedList(list);
    printf("\n");
    printf("addLeft node 0 to the list \n");
    addLeft(list, 0);
    PrintLinkedList(list);
    printf("\n");
    printf("addRight node 2 to the list \n");
    addRight(list, 2);
    PrintLinkedList(list);
    printf("\n");
    printf("insert node 0 at index 1 to the list \n");
    insertAt(list, 1, 0);
    PrintLinkedList(list);
    printf("\n");
    printf("Is 10 in the list? \n");
    printf("The hasValue return %d \n", hasValue(list, 10));
    printf("0 means False, 1 means True");
    printf("\n");
    printf("Remove right in the list \n");
    removeRight(list);
    PrintLinkedList(list);
    printf("\n");
    printf("Remove left in the list \n");
    removeLeft(list);
    PrintLinkedList(list);
    printf("\n");
    printf("Remove value at index 1 \n");
    removeAt(list, 1);
    PrintLinkedList(list);
    printf("\n");
    DestroyLinkedList(list);
    return 0;
}
