#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1500
// Approach1 using argc & argv
//int main(int argc, char* argv[]){
   // int counter;
   // printf("Program Name Is: %s",argv[0]);
   // if(argc==1)
       // printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
   // if(argc>=2)
   // {
   //     printf("\nNumber Of Arguments Passed: %d",argc);
     //   printf("\n----Following Are The Command Line Arguments Passed----");
       // for(counter=0;counter<argc;counter++)
         //   printf("\nargv[%d]: %s",counter,argv[counter]);
   // }
   // return 0;
// }

// apporach2 using fgets
int main() {
    while(1) {
        char buf[MAX];
        char *token;
        // get the input and store it into the buff
        fgets(buf, MAX, stdin);
 //       printf("string is: %s\n", buf);
        char space[2] = " ";
        // get the first token
        token = strtok(buf, space);
        // walk through other tokens
        while( token != NULL ) {
            printf( "%s\n", token );
            token = strtok(NULL, space); 
        }
    }
    return 0;
}
