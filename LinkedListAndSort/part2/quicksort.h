#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#ifndef QUICKSORT_H

#define QUICKSORT_H
typedef struct AList {
    int* list;
    int length;
}AList, *AListPtr;

void printAll(AList* alist);

void swap(AList* alist, int left, int right);

void insertionsort(AList* alist, int start, int end); 

void quicksort(AList* alist, int start, int end);

void quicksortMedian(AList* alist, int start, int end);

void quicksortPlusInsertionsort(AList* alist, int start, int end);

void bubblesort(AList* alist, int end);

int medianOfThree(AList* alist, int start, int end);

int partition(AList* alist, int pivot, int end);

void add(AList* alist, int val);

AList* create(int val);

AList* makeArray(int size);

void bubbleSortTest(int size);

void quickSortFirstTest(int size);

void quickSortMedianTest(int size);

void quickSortInsertionTest(int size);
#endif
