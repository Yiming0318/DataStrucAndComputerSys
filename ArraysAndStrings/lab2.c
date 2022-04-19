#include <stdio.h>
#include <string.h>
#include <ctype.h>
/**
 * Write a function that replaces all numbers greater
 * than ceiling in arr with ceiling.
 * 
 * Precondition(s):
 * - len > 0 (i.e. arrays MUST have at least one element)
 *  
 * Example(s):
 * - crop_hi([1, 2, 3, 4], 4, 2) :: [1, 2, 2, 2]
 * - crop_hi([-3, 17,  7, -12, 10], 5, 8) :: [-3, 8, 7, -12, 8]
 *     
 * @param arr     array of integers
 * @param len     length of arr
 * @param ceiling upper limit for ints in array
 */
void crop_hi(int* arr, int len, int ceiling){
	int i;
	for(i = 0; i < len; i++){
		if(arr[i] > ceiling){
			arr[i] = ceiling;
		}
	}
}


void print_array(int* arr, int len){
	int i;
	for(i = 0; i < len; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

void print_crop_hi_ouptput(int* arr, int len, int ceiling){
	printf("The original array is\n");
	print_array(arr, len);
        printf("len is %d and ceiling is %d \n", len, ceiling);
        crop_hi(arr, len, ceiling);
        printf("After using crop_hi, array is\n");
        print_array(arr, len);
	printf("\n");
}


/**
 * Swaps the the last int in arr with the middle element in arr.
 *
 * Precondition(s):
 * - len > 0 (i.e. arrays MUST have at least one element)
 *  
 * Example(s):
 * - swap_mid_back([1, 2, 3], 3) :: [1, 3, 2]
 * - swap_mid_back([-4, 3, 0, 1], 4) :: [-4, 1, 0, 3]
 *      
 * @param arr array of integers
 * @param len length of arr
 */
void swap_mid_back(int* arr, int len){
	int left = 0;
	int right = len - 1;
	int mid = left + (right - left) / 2;
	int arr_last_value = arr[right];
	int arr_mid_value = arr[mid];
	arr[right] = arr_mid_value;
	arr[mid] = arr_last_value;
}

void print_swap_mid_back_output(int* arr, int len){
        printf("The original array is\n");
        print_array(arr, len);
	swap_mid_back(arr, len);
        printf("After using swap_mid_back, array is\n");
        print_array(arr, len);
	printf("\n");
}


/**
 * Replaces all digits in a string with a '*'. 
 *
 * 
 * Example(s):
 * - redact("The part failed 58% of the time") ::
 *          "The part failed **% of the time"
 * - redact("There were 13 As in the class") ::
 *          "There were ** As in the class"
 *    
 * @param  str      host string for old_char
 */
void redact(char* str){
	//char star[] = "*";
	int len = strlen(str);
	int i;
	for(i = 0; i < len; i++){
	//for(int i = 0; str[i]; i++){
                if(isdigit(str[i])){
                        str[i] = '*';
                }
        }
	
}

int main(){
	printf("Test the function crop_hi \n");
	int arr[4] = {1, 2, 3, 4};
	int len = 4;
	int ceiling = 2;
	print_crop_hi_ouptput(arr, len, ceiling);
	int arr2[5] = {-3, 17, 7, -12, 10};
	int len2 = 5;
	int ceiling2 = 8;
        print_crop_hi_ouptput(arr2, len2, ceiling2);  

	printf("Test the function swap_mid_back \n");
        int arr3[3] = {1, 2, 3};
        int len3 = 3;
        print_swap_mid_back_output(arr3, len3);
        int arr4[4] = {-4, 3, 0, 1};
        int len4 = 4;
 	print_swap_mid_back_output(arr4, len4);
	int arr5[1] = {0};
	int len5 = 1;
	print_swap_mid_back_output(arr5, len5);
	


	printf("Test the function redact \n");
	char str[] = "The part failed 58% of the time";
	printf("%s\n", str);
	redact(str);
	printf("%s\n", str);
	printf("\n");
	
	char str2[] = "There were 13 As in the class";
	printf("%s\n", str2);
        redact(str2);
        printf("%s\n", str2);
	
	return 0;
}

