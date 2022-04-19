#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
typedef struct AList {
    int* list;
    int length;
}AList, *AListPtr;

void printAll(AList* alist){
    int i;
    for(i=0; i<alist->length; i++) {
        printf("%d, ", alist->list[i]);
    }
    printf("\n");
}

void swap(AList* alist, int left, int right) {
    int temp = alist->list[left];
    alist->list[left] = alist->list[right];
    alist->list[right] = temp;
}

//insertion sort
void insertionsort(AList* alist, int start, int end){
        int i;
        for(i = start + 1; i < end+1; i++){
                int val = alist->list[i];
                int j = i;
                while(j > start && alist->list[j-1] > val){
                        alist->list[j] = alist->list[j-1];
                        j -= 1;
                }
                alist -> list[j] = val;
                }
}

//Algorithm1, use the first element of array as the pivot
void quicksort(AList* alist, int start, int end){
    //check for base cases
    //select a pivot
    //partition around pivot
    //recurse on the left and right
    if(start >= end) return;

    int pivot = partition(alist, start, end);
    quicksort(alist, start, pivot-1);
    quicksort(alist, pivot + 1, end);
}

//Algorithm2, use the median as the pivot
void quicksortMedian(AList* alist, int start, int end){
	if(start >= end) return;
	int median = medianOfThree(alist,start,end);
	swap(alist, start, median);//swap median to the first
	int pivot = partition(alist, start, end);	 
	quicksortMedian(alist, start, pivot-1);
	quicksortMedian(alist, pivot+1, end);
}

//Algorithm3, quickSort with insertion sort
void quicksortPlusInsertionsort(AList* alist, int start, int end){
	if(start < end){
		if((end - start) < 7){ // set the threshold to 7,switch to Insertionsor
			insertionsort(alist, start, end + 1);
		}else{
		quicksort(alist, start, end);
		}
	}
}

//Algorithm4, bubble sort
void bubblesort(AList* alist, int end){
	int i, j;
	for(i = 0; i < end - 1; i++)
		for(j = 0; j < end-i-1; j++)
			if(alist->list[j] > alist->list[j+1])
				swap(alist, j, j+1);
}	
			

//function to find the pivot using median of three
int medianOfThree(AList* alist, int start, int end){
	int mid = start + (end - start) / 2;//avoid long int error
	int first = alist -> list[start];
	int last = alist -> list[end];
	int middle = alist -> list[mid];
	if(last < first) swap(alist, start, end);
	if(middle < first) swap(alist, start, mid);
	if(last < middle) swap(alist, mid, end);
	return mid;
}


int partition(AList* alist, int pivot, int end) {
    //check for base cases
    //if pivot == end || end - pivot == 1 && list[end] > list[pivot] return
    //if value to right is larger, swap with end
    //if value to right is smaller, swap with pivot
 //   printf("pivot is %d and end is %d\n", pivot, end);

    if(pivot == end || (end - pivot == 1 && alist->list[pivot] < alist->list[end])){
   //     printf("returning\n");
        return pivot;
    }

    if(alist->list[pivot] < alist->list[pivot + 1]) {
        swap(alist, pivot + 1, end);
        return partition(alist, pivot, end - 1);
    } else {
        swap(alist, pivot, pivot + 1);
        return partition(alist, pivot + 1, end);
   }
}


void add(AList* alist, int val) {
    int* arr = (int*)malloc(sizeof(int) * (alist->length + 1));
    int* temp = alist->list;

    int i;
    for(i=0; i<alist->length; i++) {
        arr[i] = alist->list[i];
    }
    arr[alist->length] = val;
    alist->list = arr;
    alist->length = alist->length + 1;
    free(temp);
}

AList* create(int val) {
    int* l = (int*)malloc(sizeof(int));
    l[0] = val;

    AList* alist = (AList*)malloc(sizeof(AList));
    alist->list = l;
    alist->length = 1;

    return alist;
}

AList* makeArray(int size){
	const int MIN = -99;
        const int MAX = 99;
        srand(27);
        int i;
	AList* alist = create(88);
        for (i = 1; i < size; i++){
                int randomNum = MIN + (rand() % (MAX -MIN));
                add(alist, randomNum);
        }
	return alist;
}

void bubbleSortTest(int size){
	AList* alist =  makeArray(size);
        struct timeval tv1, tv2;
        gettimeofday(&tv1, NULL);
        bubblesort(alist,alist->length);
        gettimeofday(&tv2, NULL);
        double time = (double)(tv2.tv_usec - tv1.tv_usec)/1000000 + (double)(tv2.tv_sec - tv1.tv_sec);
        printf("BubbleSort sorting time %f s \n", time);
        free(alist->list);
        free(alist);

}

void quickSortFirstTest(int size){
	AList* alist =  makeArray(size);
        struct timeval tv1, tv2;
        gettimeofday(&tv1, NULL);
        quicksort(alist, 0, alist->length - 1);
	gettimeofday(&tv2, NULL);
        double time = (double)(tv2.tv_usec - tv1.tv_usec)/1000000 + (double)(tv2.tv_sec - tv1.tv_sec);
        printf("QuickSort using first pivot sorting time %f s \n", time);
	free(alist->list);
        free(alist);
}

void quickSortMedianTest(int size){
	AList* alist =  makeArray(size);
        struct timeval tv1, tv2;
        gettimeofday(&tv1, NULL);
        quicksortMedian(alist, 0, alist->length - 1);
	gettimeofday(&tv2, NULL);
        double time = (double)(tv2.tv_usec - tv1.tv_usec)/1000000 + (double)(tv2.tv_sec - tv1.tv_sec);
        printf("QuickSort using median pivot sorting time %f s \n", time);
        free(alist->list);
        free(alist);

}

void quickSortInsertionTest(int size){
	AList* alist =  makeArray(size);
        struct timeval tv1, tv2;
        gettimeofday(&tv1, NULL);
        quicksortPlusInsertionsort(alist, 0, alist -> length - 1); 
        gettimeofday(&tv2, NULL);
        double time = (double)(tv2.tv_usec - tv1.tv_usec)/1000000 + (double)(tv2.tv_sec - tv1.tv_sec);
        printf("QuickSort hybird with InsertionSort sorting time %f s \n", time);
        free(alist->list);
        free(alist);

}


int main() {
	printf("Size of the array is 16 \n");
   	bubbleSortTest(16);	
 	quickSortFirstTest(16);   	
	quickSortMedianTest(16);
	quickSortInsertionTest(16);
	printf("\n");
	printf("Size of the array is 64 \n");
        bubbleSortTest(64);
        quickSortFirstTest(64);
        quickSortMedianTest(64);
        quickSortInsertionTest(64);
	printf("\n");
	printf("Size of the array is 128 \n");
        bubbleSortTest(128);
        quickSortFirstTest(128);
        quickSortMedianTest(128);
        quickSortInsertionTest(128);
	printf("\n");
        printf("Size of the array is 512 \n");
        bubbleSortTest(512);
        quickSortFirstTest(512);
        quickSortMedianTest(512);
        quickSortInsertionTest(512);
	printf("\n");
        printf("Size of the array is 1024 \n");
        bubbleSortTest(1024);
        quickSortFirstTest(1024);
        quickSortMedianTest(1024);
        quickSortInsertionTest(1024);
	printf("\n");
        printf("Size of the array is 2048 \n");
        bubbleSortTest(2048);
        quickSortFirstTest(2048);
        quickSortMedianTest(2048);
        quickSortInsertionTest(2048);
	return 1;
    }
