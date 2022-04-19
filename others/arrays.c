#include<stdio.h>

void populate(int array[]){
	int i;
	 for(i=0;i<10;i++){
                arr[i] = i;
        }
       // return array;
}
void printValues(int array[]){
}
int main(){
	int size = 10;
	int arr[size]; 
	//for(i=0;i<10;i++){
		//arr[i] = i;
	//}
	populate(arr,size)
	int j;
	for(j=0;j<10;j++){
		printf("the values of array are %d\n", arr[j]);
	}
	return 0;
}

