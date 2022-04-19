#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "a2.h"
#include <ctype.h>

// YOUR CODE GOES HERE
// CS5008
// Assignment 2
// Yiming Ge
// Feb 09 2022


//Bonus: Transfor the name to legal form
//eg input jAmes
//   return James
char* formatLeg(char s[]){
 	int i;
 	char* s2;
 	// calloc memory avoid uninitialized value error in valgrind 
 	s2 = (char*)calloc(sizeof(s2), sizeof(s));
 	if( s2  == NULL ){
 	            return NULL;
 	     }
 	// Executing till null character
 	// is found
        for (i = 1; s[i]; i++) {
 	     // Copy the character one
            // by one from s1 to s2, ignore the first one
          	s2[i] = tolower(s[i]);
        }
        // copy the first one to s2 
        s2[0] = toupper(s[0]);      
	// Return the pointer of newly
        // created string
        return (char*)s2;
 }
  


//
// Print the string <first> <middle> <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben Ivan Bitdiddle".
//
//  If the middle name is NULL, then print:
//  "Ben Bitdiddle"
//
//  name: a pointer to a Name
void Big(Name *name) {
	char* first = formatLeg(name ->first);
	char* last = formatLeg(name->last);	
	// The condition for middle name
	if(name -> middle){//if middle name exists
		char* middle = formatLeg(name -> middle);
		printf("%s %s %s\n", first, middle, last);
		free(middle);
	}else{
		printf("%s %s\n", first, last);
	}
	free(first);
	free(last);
}

// Print the string <last>, <first>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Bitdiddle, Ben".
//
// name: a pointer to a Name
void Last(Name *name) {
	char* first = formatLeg(name ->first);
 	char* last = formatLeg(name->last);	
	printf("%s, %s\n", last, first);
	free(first);
	free(last);
}

// Print the string <first> <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben Bitdiddle".
//
// name: a pointer to a Name
void Reg(Name *name) {
	char* first = formatLeg(name ->first);
 	char* last = formatLeg(name->last);
	printf("%s %s\n", first, last);
	free(first);
	free(last);
}


// Print the string <first> <middle-initial>. <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben I. Bitdiddle".
//
// If middle name is NULL, print:
// "Ben Bitdiddle"
//
// name: a pointer to a Name
void Mid(Name *name) {
	char* first = formatLeg(name ->first);
 	char* last = formatLeg(name->last);
	if(name->middle){ //if middle exists, print the first char of the middle string
		char* middle = formatLeg(name->middle);
		printf("%s %c. %s\n", first, middle[0], last);
		free(middle);
	}else{			
		printf("%s %s\n", first, last);
	}
	free(first);
 	free(last);

}


// Print the first name only.
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben".
//
// name: a pointer to a Name
void Small(Name *name){
	char* first = formatLeg(name -> first);
	printf("%s\n", first);
	free(first);
}


// Given a format char, print the given
// name in the format specified by char.
// The mapping is shown below:
// B -> 'big' format
// L -> 'last' format
// R -> 'reg' format
// M -> 'mid' format
// S -> 'small' format
//
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
void FormatName(Name *name, char format){
	if(format == 'b' || format == 'B'){
		Big(name);
	}else if(format == 'l' || format == 'L'){
		Last(name);
	}else if(format == 'r' || format == 'R'){
		Reg(name);
	}else if(format == 'm' || format == 'M'){
		Mid(name);
	}else if(format == 's' || format == 'S'){
		Small(name);
	}else{
		printf("wrong format");
	}
}

	
// Given a name, a format and a destination array,
// put the properly formatted name in the destination
// array, not printing anything on the screen.
//
// The mapping is shown below:
// B -> 'big' format
// L -> 'last' format
// R -> 'reg' format
// M -> 'mid' formar* first = format(name ->first);
//         char* last = format(name->last);t
// S -> 'small' format
//
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
// dest: a pointer to an array that is guaranteed to be big enough
// to hold the formatted name
void FillName(Name *name, char format, char *dest) {
	char* space = " ";
	char* dot = ".";
	char* comma = ",";
	if(format == 'b' || format == 'B'){
		char* first = formatLeg(name->first);
		char* last = formatLeg(name->last);
        	if(name->middle){//if middle name exists
		char* middle = formatLeg(name->middle);
		//add two space , sizeof already calculates two more \0
		int size = (sizeof(first) + sizeof(last) + sizeof(middle));
		snprintf(dest,size ,"%s %s %s", first, middle, last);   
		free(middle);
        	}else{
		// add one space (already count one more \0)
		int size = (sizeof(first) + sizeof(last));
		snprintf(dest,500,"%s %s", first,last);   
		}
		free(first);
		free(last);
        }else if(format == 'l' || format == 'L'){
                char* first = formatLeg(name->first);
                char* last = formatLeg(name->last);
		//add one space one comma (already count one more \0)
		int size = (sizeof(first) + sizeof(last)+1);
		snprintf(dest,size,"%s, %s",last, first);
		free(first);
		free(last);
        }else if(format == 'r' || format == 'R'){
		char* first = formatLeg(name->first);
		//normal size no need change
		int size = (sizeof(first));
		snprintf(dest,size,"%s",first);
		free(first);
        }else if(format == 'm' || format == 'M'){
		char* first = formatLeg(name->first);
		char* last = formatLeg(name->last);
		if(name->middle){//if middle name exists
			//get the first char of string array to cap
			char* mid = name->middle;
			char strMid[2];
			strMid[0] = toupper(mid[0]);
			strMid[1] = '\0';
			//add two space, ond dot, one char
			//(already count one more \0)
			int size = (sizeof(first) + sizeof(last) + 3);
			snprintf(dest,size,"%s %s. %s",first, strMid, last);
			//free(middle);
		}else{
			//add one space, (already count one more \0)		
			int size = (sizeof(first) + sizeof(last));
               		snprintf(dest,size,"%s %s",first, last);	
		}
		free(last);
		free(first);
        }else if(format == 's' || format == 'S'){
		char* first = formatLeg(name->first);
		//normal size, no need change
		int size = sizeof(first);
		snprintf(dest,size,first);
		free(first);              
        }else{
                printf("wrong format");
       }

}

