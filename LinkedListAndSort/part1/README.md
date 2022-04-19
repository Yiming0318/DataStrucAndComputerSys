## Basic Info
```
Yiming Ge
CS5008 Assignment3 Part One
Takes more than 6 hour
Spend lots of time to figure out the valgrind, why the valgrind keep running? Is the linked list too large? or is there any problem with my malloc.
Base on piazza discussion, try to give the node and list more bytes manually.(It seems like the problem is wifi or network problem. Valgrind works sucessfully and no errors after I using school wifi instead of the home internet.)
```


## Sample Output
```
size of linkedlist is 50
presorted list is 11 -13 12 -19 -19 7 14 -2 -20 -14 -2 4 -11 20 -25 -3 -28 -12 -17 -25 -26 -18 2 20 27 27 20 2 -18 -26 -25 -17 -12 -28 -3 -25 20 -11 4 -2 -14 -20 -2 14 7 -19 -19 12 -13 11 
After Insertion Sort 
postsorted list is -28 -28 -26 -26 -25 -25 -25 -25 -20 -20 -19 -19 -19 -19 -18 -18 -17 -17 -14 -14 -13 -13 -12 -12 -11 -11 -3 -3 -2 -2 -2 -2 2 2 4 4 7 7 11 11 12 12 14 14 20 20 20 20 27 27 

```


## Reference
```
[invalid read of size 8](https://stackoverflow.com/questions/4035769/invalid-read-of-size-8-valgrind-c)
[piazza discussion](https://piazza.com/class/kym9nmbdky433w?cid=106)
[Valgrind FAQ](https://www.cs.cmu.edu/afs/cs.cmu.edu/project/cmt-40/Nice/RuleRefinement/bin/valgrind-3.2.0/docs/html/faq.html)
[invalid write of size 8](https://stackoverflow.com/questions/7668499/valgrind-complains-with-invalid-write-of-size-8)

```
