#include<stdio.h>
struct Person{
	char* firstName;
	int* age;
};
int main(){
	struct Person p;
	p.firstName = "Drew";
	int j = 10;
	p.age = &j;
	printf("The first name is %s\n and the age os %d\n", p.firstName, *p.age);
	return 0;
}
