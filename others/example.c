#include <stdio.h>

int main(){
	int accountId = 5;
	double accountBalance = 100.53;
	char accountType = 'C';
	printf("AccountID is: %d\n",accountId);
	printf("AccountBL is: %f\n",accountBalance);
	printf("AccountTY os: %c\n",accountType);
	
	printf("sizeof(int): %d\n", sizeof(int));
	printf("sizeof(double):%d\n",sizeof(double));
	printf("sizeof(char):%d\n",sizeof(accountType));
	return 0;
}
