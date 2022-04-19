/*
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  It is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  See <http://www.gnu.org/licenses/>.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// This struct represents an individual node within a linked list.  A node
// contains next and prev pointers as well as a customer-supplied payload
// pointer.
typedef struct ll_node {
    void* data;  // Pointer to a string, most likely on the heap
    struct ll_node *next;     // next node in list, or NULL
    struct ll_node *prev;     // prev node in list, or NULL
} LinkedListNode, *LinkedListNodePtr;

// This struct represents the entire linked list.  We provided a struct
// declaration (but not definition) in LinkedList.h; this is the associated
// definition.  This struct contains metadata about the linked list.
typedef struct ll_head {
    int num_elements;  //  # elements in the list
    LinkedListNodePtr head;  // head of linked list, or NULL if empty
    LinkedListNodePtr tail;  // tail of linked list, or NULL if empty
} LinkedListHead, *LinkedList;


// Creates a LinkedListNode by malloc'ing the space.
//
// INPUT: A pointer that the payload of the returned LLNode will point to.
//
// Returns a pointer to the new LinkedListNode.
LinkedListNode* CreateLinkedListNode(void *data);

// Destroys and free's a provided LLNode.
//
// INPUT: A pointer to the node to destroy.
//
// Returns 0 if the destroy was successful.
int DestroyLinkedListNode(LinkedListNode *node);


// ======================================================
// LinkedList: A Doubly-Linked List
// ======================================================

// Creates a LinkedList.
// The customer is responsible for calling DestroyLinkedList()
// to destroy and free the LinkedList when done.
//
// Returns a LinkedList; NULL if there's an error.
LinkedList CreateLinkedList();

// Destroys a LinkedList.
// All structs associated with a LinkedList will be
// released and freed. Payload_free_function will
// be used to free the payloads in the list.
//
// INPUT: A pointer to a LinkedList.
// INPUT: A pointer to a function used to free the payload.
//
// Returns 0 if the destroy was successful; non-zero for failure.
int DestroyLinkedList(LinkedList list);


// Returns the number of elements in the linked list.
//
// INPUT: A LinkedList
//
// Returns the number of elements in the list.
unsigned int NumElementsInLinkedList(LinkedList list);

// Adds an element to the head of a LinkedList, with the string
// as the given pointer.
// The customer is responsible for allocating the string.
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A pointer to a string for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int InsertLinkedList(LinkedList, void* data);

#endif  // LINKEDLIST_H
