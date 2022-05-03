# Multi-threaded Searching
```
Name: Yiming Ge

Info: use make run to run the program
      use make val_test to valgrind test the program
(default:./mt_search inputs/input1.txt 5 2 10)

Smaple output:
The file path is inputs/input1.txt
The target is 5
The number of threads is 2
Search the first 10 lines in the file
================================== 
About to spawn threads
Starting thread 0
Starting thread 1
START SEARCH THREAD 1 
In thread id = 1, target 5 found at index 5!
FINISH SEARCH THREAD 1 
START SEARCH THREAD 0 
FINISH SEARCH THREAD 0 
Threads have joined
Locations of Target are: 
index 5
```

# Observations and General Idea for multithread
```

Each thread deals with a section of the number array
Simple even len data example: data = [0,1,2,3], thread = 2, target = 2
we have two sections here
thread 0 deal with [0, 1]
thread 1 deal with [2, 3]
we can find 2 in thread 2.

Another odd len data example: data = [0,1,2,3,4], thread = 2, target = 2
we have two sections here
thread 0 deal with [0, 1, 2]
thread 1 deal with [3, 4]
we can find 2 in thread 1.

```

# External resources
https://thispointer.com/posix-how-to-create-a-thread-pthread_create-example-tutorial/
https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm
https://blog.csdn.net/amj0622/article/details/5636328
https://www.jianshu.com/p/a2ade02979d1
https://www.howtogeek.com/778790/how-to-copy-files-and-directories-in-linux-terminal/#:~:text=Using%20the%20cp%20Command,files%20to%20a%20single%20directory.
https://www.tutorialspoint.com/linear-search-using-multi-threading-in-c
https://www.geeksforgeeks.org/fgets-gets-c-language/
https://www.geeksforgeeks.org/c-program-to-read-contents-of-whole-file/



