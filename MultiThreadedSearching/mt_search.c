#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

// ****************************
// This code is provided as an *optional* framework to use to
// write your multi-threaded search code for Assignment A8.
//
// Feel free to change anything you want to in this.
// ****************************


// ===================================================
// Global Variables
// ===================================================
#define MAX_CHAR 4    // since the largest number is 999
#define MAX_NUM_RESULTS 100
int num_data_points;
int section_size;
int number_of_lines;

// Array of numbers to search
int* data;
int* location;
// Number to be found
int target;

// Array of indices of target number
int results[MAX_NUM_RESULTS];
// Number of results we have so far
int num_results = 0;


// Used for synchronization.
// I encourage you to rename this something more meaningful.
pthread_mutex_t lock;
sem_t semaphore;

// All the threads (an array)
pthread_t* threads;

// ===================================================
// Functions
// ===================================================

// The function that each thread will run
// to look for the target value in the array.
// The argument provided is a pointer to the array.
// where this thread should start looking for the target.
// (This can be either the index OR the address. Your choice.)
// Each thread will look at a max of section_size elements.
void* DoSearch(void* start_address) {
    int start = *(int *) start_address;  // index of the start_number in array
    int length = start + section_size;  // end length for this thread
    // try to yield to other threads
    sleep(2);
    // wait for the semaphore
    sem_wait(&semaphore);
    printf("START SEARCH THREAD %d \n", (int)(start / section_size));
    // linear search
    int i;
    for (i = start; i < length; i++) {
        if (data[i] == target) {
            printf("In thread id = %d, target %d found at index %d!\n", (int)(start / section_size), target, i);
        // store the results
        results[num_results++] = i;
        }
     }
    printf("FINISH SEARCH THREAD %d \n", (int)(start / section_size));
    // release the semaphore
    sem_post(&semaphore);
    return NULL;
}

// Calculate the section size for each thread
void CalculateSectionSize(int num_threads) {
    if (number_of_lines % num_threads == 0) {
        section_size = number_of_lines / num_threads;
    } else {
        section_size = number_of_lines / num_threads + 1;
    }
}


// Creates all the threads and starts them running.
// Makes sure the thread IDs are stored in the global threads array.
void MakeThreads(int num_threads) {
    pthread_t thread_id[num_threads];
    CalculateSectionSize(num_threads);
    printf("About to spawn threads\n");
    int i;
    for (i = 0; i < num_threads; i++) {
        printf("Starting thread %d\n", i);
        // each thread start at the index based on the location array index
        pthread_create(&thread_id[i], NULL,
        DoSearch, &location[i*section_size]);
  }
    for (i = 0; i < num_threads; i++) {
        pthread_join(thread_id[i], NULL);
  }
  printf("Threads have joined\n");
}

// Opens the file called filename.
// Reads line by line, adding each number to the
// global data array.
int ReadFile(char* filename) {
    FILE* read_ptr;
    read_ptr = fopen(filename, "r");
    if (NULL == read_ptr) {
        printf("file cannot be opened \n");
        return 0;
    }
    int i;
    char line[MAX_CHAR];
    data = malloc(sizeof(int) * number_of_lines);
    location = malloc(sizeof(int) * number_of_lines);
    for (i = 0; i < number_of_lines; i++) {
        if (fgets(line, MAX_CHAR, read_ptr)!= NULL) {
         data[i] = atoi(line);
         location[i] = i;
        }
    }
    fclose(read_ptr);
    return 1;
}


// Prints out the results, stored in the
// global "results" array.
void PrintResults() {
    printf("Locations of Target are: \n");
    int i;
    for (i = 0; i < num_results; i++) {
        printf("index %d\n", results[i]);
    }
}

int main(int num_args, char* args[]) {
    // START HERE
    // Read in the arguments and populate global variables.
    char* file_path = args[1];
    printf("The file path is %s\n", file_path);
    target = atoi(args[2]);
    printf("The target is %d\n", target);
    int number_of_threads = atoi(args[3]);
    printf("The number of threads is %d\n", number_of_threads);
    number_of_lines = atoi(args[4]);
    printf("Search the first %d lines in the file\n", number_of_lines);
    printf("================================== \n");
    // Read the file
    ReadFile(file_path);
    // Wait for threads to finish doing their job
    sem_init(&semaphore, 0, 1);
    MakeThreads(number_of_threads);
    // Print out the results
    PrintResults();
    // Clean up everything!
    // Free everything you malloc'd.
    // Don't forget to destroy the semaphore and mutex, which
    // get malloc'd when you create them.
    free(data);
    free(location);
    sem_destroy(&semaphore);
    exit(0);
}
