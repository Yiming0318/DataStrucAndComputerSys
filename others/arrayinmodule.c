#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int array[3] ={ 1, 2, 3};
//fast way to claim array
/*	array[0] = 12;
	array[1] = 24;
	array[2] = 36;
*/
	double array2[3] = {1.5, 2.3, 3.8};
	char array3[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
	char array4[] = "Hello World!";
	printf("%s %s\n", array3, array4);
	for( int i = 0; i < 3; i++){
		printf("%d\n", array[i]);
	}
	return 0;
}
