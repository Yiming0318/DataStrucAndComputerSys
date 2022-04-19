#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "sort.h"
#include "operationtest.h"
#include "linkedlist.h"

void printListData(LinkedListPtr list) {
    printf("Number of elements is %d\n", list->num_elements);
}

int main(int argc, char *argv[]) {
    bool debug = false;

    int i;
    for(i = 0; i<argc; i++) debug = debug || strcmp(argv[i],"-d") == 0;
    
    if(debug) printf("Debug enabled.\n");

    LinkedListPtr list = (LinkedListPtr) malloc(sizeof(struct ll_head));

    list->head = NULL;
    list->tail = NULL;
    list->num_elements = 0;

    if(debug) printListData(list);

    AppendLinkedList(list, 1);
    
    if(debug) printListData(list);

    testOperations(list, debug);
}

