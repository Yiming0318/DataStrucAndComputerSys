//Yiming Ge
//CS5008
//Assignment2
//Feb 09 2022

//section1
void PointerTest() {
// allocate three integers and two pointers
	int a = 1;
	int b = 2;
	int c = 3;
	int* p;
	int* q;
	p = &a; // set p to refer to a
	q = &b; // set q to refer to b
	c = *p; // retrieve p's pointee value (1) and put it in c
	p = q; // change p to share with q (p's pointee is now b)
	*p = 13; // dereference p to set its pointee (b) to 13 (*q is now 13)
}

// Local storage example
int Square(int num) {
	int result;
	result = num * num;
	return result;
}

// B() now uses a reference parameter -- a pointer to
// the value of interest. B() uses a dereference (*) on the
// reference parameter to get at the value of interest.
void B(int* worthRef) { // reference parameter
	*worthRef = *worthRef + 1; // use * to get at value of interest
	// T2
}
void A() {
	int netWorth;
	netWorth = 55; // T1 -- the value of interest is local to A()
	B(&netWorth); // Pass a pointer to the value of interest.
		     // In this case using &.
// T3 -- B() has used its pointer to change the value of interest
}


void Swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void SwapCaller() {
	int x = 1;
	int y = 2;
	Swap(&x, &y); // Use & to pass pointers to the int values of interest
		      // (x and y).
}


int main(){

	return 0;
}
