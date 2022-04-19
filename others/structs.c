#include <stdio.h>

struct student{
	int id;
	int age;
	double creditHours;
};

struct student makeStudent(int id, int age, double creditHours){
	struct student st;
	st.id = id;
        st.age = age;
        st.creditHours = creditHours;
	return st;
};

void printStudent(struct student aStudent){
	printf("Student: %d %d %f\n", aStudent.id,
				      aStudent.age,
				      aStudent.creditHours);
}

int main(){
/*	struct student s1;
	s1.id = 1001;
	s1.age = 23;
	s1.creditHours = 14.5;

	struct student s2;
	s2.id = 1001000;
        s2.age = 21;
        s2.creditHours = 14;
*/

	struct student s1 = makeStudent(100, 24, 3.0);
	struct student s2 = makeStudent(1001, 20, 4.0);
/*	printf("Student: %d %d %f\n", s2.id, s2.age, s2.creditHours);
	printf("Student: %d %d %f\n", s1.id, s1.age, s1.creditHours);
*/
	printStudent(s1);
	printStudent(s2);
	return 0;
}
