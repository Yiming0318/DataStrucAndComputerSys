Who did you work with (if anyone)
Myself

How long did this take you? 
50 mins

[Optional] What did you like about this lab? 

[Optional] What could be improved about this lab?

Where's the error?
For grades.c , the problem is that we did not free the memory after the program end. Thus, we should add free(p); after printf("\nAverage marks = %.2f\n", sum/n);


For errors.c, the problem is use of an uninitialized value and a leak. 
Since sizeof operates on a TYPE, we are no longer using the stringOnHeap var
while we initialize it. And make sure check whether the malloc succeeded or
failed before continuing to avoid the crash.
We also should free the block after the printf("%s\n", stringOnHeap);
