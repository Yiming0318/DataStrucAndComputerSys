#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
        int* data;
        int size;
        int capacity; //the max size of the array, eg 5 [1,2, , , ]
}vector_t;



vector_t* makeVector(int initCapacity){
	vector_t* vector = (vector_t*)malloc(sizeof(vector_t));
	if( vector == NULL ){
		return NULL;
	}
	//Allocate memory for our data array.
	vector->data = (int*)malloc(sizeof(int) * initCapacity);
	vector->size = 0;
	vector->capacity = initCapacity;
	return vector;
}


void freeVector(vector_t* vector){
	if ( vector == NULL){
		return;
	}
	//First delete the data array, then delete the vector.
	if( vector->data != NULL){
		free(vector->data);
	}
	free(vector);
}

int resize(vector_t* vector){
	if(vector == NULL){
		return 0;
	}
	vector->capacity = vector->capacity * 2;
	int* newData = (int*)malloc(sizeof(int) * vector->capacity);
	if (newData == NULL || vector->data == NULL){
		return 0;
	}
	//We need to copy the data from the old array into new array
	int i;
	for(i = 0; i< vector->size; i++){
		newData[i] = vector->data[i];
	}
	//free the old data, scine now the data already stored into the newData
	free(vector->data);
	vector->data = newData;
	return 1;
}



//add the element to the end of a vector
int push_back(vector_t* vector, int element){
	if(vector == NULL){
		return 0;
	}	
	if(vector->data == NULL){
		return 0;
	}
	//check to make sure that we have enough room.
	//Do we have to resize our data
	if (vector->size == vector->capacity){
		int resizeSuccess = resize(vector);
		if (resizeSuccess == 0){
			return 0;
		}
	}
	//lets go ahead and append to the back of the array;
	vector->data[vector->size] = element;
	vector->size += 1;
	return 1;
}


//insert the element to the vector
int insert(vector_t* vector, int pos, int element){
        if(vector == NULL || pos<0){
       		 return 0;
         }
	if (pos == vector ->size){
		return push_back(vector,element);
	}
	
	if ( vector -> size == vector->capacity){
		int successOnResize = resize(vector);
                if (successOnResize == 0){
                	return 0;
                  }
	}	
	if(vector->data == NULL){
		return 0;
	}
	int i;
	//shift origin data backwards 1 position
	for(i = vector->size - 1; i >= pos; i--){
		vector->data[i+1] = vector -> data[i];
	}
	vector -> data[pos] = element;
	vector-> size += 1;
	return 1;	
}



//add to the first position in array
int push_front(vector_t* vector, int element){
	return insert(vector, 0, element);
}






void print(vector_t* vector){
	if(vector == NULL){
		return;
	}
	if(vector->data == NULL){
		return;
	}
	int i;
	for (i = 0; i< vector -> size; i++){
		printf("%d", vector->data[i]);
	}
	printf("\n");
}




int main(){
	//Constructed a vector on the heap
	vector_t* vector = makeVector(2);
	push_back(vector, 2);
	push_back(vector, 4);
	push_back(vector, 6);
	push_back(vector, 8);
	push_back(vector, 9);
	print(vector);
	push_front(vector, 1);
	print(vector);
	push_front(vector, 0);
	print(vector);
	insert(vector, 3, 3);
	print(vector);
	insert(vector, 5, 5);
	print(vector);
	insert(vector, vector->size, 10);
	print(vector);
	//delete the vector from the heap
	freeVector(vector);
	return 0;
}
