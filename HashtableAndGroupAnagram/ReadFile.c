#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Hashtable.h"


// helper function sort a word in alphabetical order
void sort(char* word) {
    char temp;
    int i;
    int j;
    int n = strlen(word);
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (word[i] > word[j]) {
                temp = word[i];
                word[i] = word[j];
                word[j] = temp;
            }
        }
    }
}


// Read the word file and create the Hashtable
// sorted word as key and original words as value

void Readfile(Hashtable ht, char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot find the file");
    } else {
        char line_input[1000];
        while (fgets(line_input, sizeof(line_input), fp)) {
            // return the number of characters in line_input until it meets \n
            int line_length = strcspn(line_input, "\n");
            line_input[line_length] = '\0';
            char* word = (char*)malloc(sizeof(*word) * (line_length + 1));
            char* sorted_word =
            (char*)malloc(sizeof(*sorted_word) * (line_length + 1));
            strncpy(word, line_input, strlen(line_input) + 1);
            strncpy(sorted_word, word, strlen(line_input) + 1);
            sort(sorted_word);
            PutInHashtable(ht, sorted_word, word);
            free(word);
            free(sorted_word);
    }
  }
  fclose(fp);
}
