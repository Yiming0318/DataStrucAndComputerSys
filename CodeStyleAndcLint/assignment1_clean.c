#include<stdio.h>

void warm_up() {
  // warm up
  int i;
  for (i = 0; i < 3; i++) {
    printf("VICTORY! \n");
  }
}

/*
 * This function prints an empty rectangle of the specified width and height. 
 * 
 */

void PrintRectangle(int width, int height) {
  int i;
  int j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if ( i ==0 || i == height - 1 ||j == 0 || j == width - 1 ) {
        printf("_");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}


/*
 *  This function prints a fancy rectangle. 
 */
void PrintFancyRectangle(int width, int height, char symbol, int fill) {
  int i;
  int j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (fill == 0) {
        if ( i ==0 || i == height - 1 || j == 0 || j == width - 1 ) {
          printf("%s", &symbol);
        } else {
          printf(" ");
        }
        } else {
          printf("%s", &symbol);
        }
     }
    printf("\n");
  }
}

int main() {
  // warm up
  printf("warmup \n");
  warm_up();
  printf("printRectangles with width 5 and height 4 \n");
  PrintRectangle(5, 4);
  printf("\n");
  printf("PrintFancyRectangle(5, 4, '+', 0): \n");
  PrintFancyRectangle(5, 4, '+', 0);
  printf("\n");
  printf("PrintFancyRectangle(5, 4, '*', 1): \n");
  PrintFancyRectangle(5, 4, '*', 1);
  return 0;
}
