#include<stdio.h>

int main(){
	int COUNT = 10;
	int j,*i[COUNT],x;
	int anotherRef[COUNT];
	int y;
	for(y=0; y<COUNT; y++){
		anotherRef[y] = y;
	}
	
	for(j=0; j<COUNT; j++){
		i[j] = &anotherRef[j];
	}

	for(x = 0; x<COUNT; x++){
		printf("The memory location is %d\n",i[x]);
		printf("The value is %d\n",*i[x]);
	}
	return 0;
}

