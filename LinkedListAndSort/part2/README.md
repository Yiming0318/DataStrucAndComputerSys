## Basic Info
```
Yiming Ge

Tricky Part: using clock() will only get the 0.0000s running time. Using gettimeofday instead.
```

## Run the Code Get the Report
```
Directly gcc quicksort.c, run the ./a.out



Sample Output:
Size of the array is 16 
BubbleSort sorting time 0.000004 s 
QuickSort using first pivot sorting time 0.000005 s 
QuickSort using median pivot sorting time 0.000005 s 
QuickSort hybird with InsertionSort sorting time 0.000004 s 

Size of the array is 64 
BubbleSort sorting time 0.000056 s 
QuickSort using first pivot sorting time 0.000023 s 
QuickSort using median pivot sorting time 0.000026 s 
QuickSort hybird with InsertionSort sorting time 0.000020 s 

Size of the array is 128 
BubbleSort sorting time 0.000159 s 
QuickSort using first pivot sorting time 0.000052 s 
QuickSort using median pivot sorting time 0.000052 s 
QuickSort hybird with InsertionSort sorting time 0.000047 s 

Size of the array is 512 
BubbleSort sorting time 0.002192 s 
QuickSort using first pivot sorting time 0.000296 s 
QuickSort using median pivot sorting time 0.000279 s 
QuickSort hybird with InsertionSort sorting time 0.000273 s 

Size of the array is 1024 
BubbleSort sorting time 0.003467 s 
QuickSort using first pivot sorting time 0.000270 s 
QuickSort using median pivot sorting time 0.000264 s 
QuickSort hybird with InsertionSort sorting time 0.000239 s 

Size of the array is 2048 
BubbleSort sorting time 0.012836 s 
QuickSort using first pivot sorting time 0.000571 s 
QuickSort using median pivot sorting time 0.000583 s 
QuickSort hybird with InsertionSort sorting time 0.000549 s 


```

## Conclusion
```
In these four algos: 
BubbleSort, QuickSort - first pivot, QuickSort - median pivot, QuickSort - hybird with Insertion sort
When size become larger, hybird quicksort is the quickest one, and bubble sort is the slowest one. 

```

## Reference
```
[Execution time Of C program] (https://stackoverflow.com/questions/5248915/execution-time-of-c-program)
[passing argument makes pointer from integer without a cast] (https://stackoverflow.com/questions/25584674/passing-argument-makes-pointer-from-integer-without-a-cast)
And a lot of ideas from geeksforgeeks.org

``` 

