# Doubly linked list & Deque

## Summary
```
Yiming Ge

What I learned: Deque can define both stack and queue, Doubly linked list has O(n) time complexity to remove or add an node with given index.

What challengs I faced: I need to draw a diagram to figure out the new node relationship with its previous and next node to add this node into the doubly linkedlist. In addition, a lot of Null edge case should be considered, otherwise there will be segmentation fault.
```

## Functionality test Output(gcc doubly.c to test the dll and gcc deque.c to test the deque)

```
Output for doubly linked list:
addLeft node 1 to the empty list 
1 
addLeft node 0 to the list 
0 1 
addRight node 2 to the list 
0 1 2 
insert node 0 at index 1 to the list 
0 0 1 2 
Is 10 in the list? 
The hasValue return 0 
0 means False, 1 means True
Remove right in the list 
0 0 1 
Remove left in the list 
0 1 
Remove value at index 1 
0 

```

```
Output for deque:
pushLeft node 1 to the empty deque 
1 
pushLeft node 0 to the deque 
0 1 
pushRight node 2 to the deque 
0 1 2 
Peek right in the deque 
The rightmost value is 2 
0 1 2 
Peek left in the deque 
The leftmost value is 0 
0 1 2 
Pop right in the deque 
The rightmost value is 2 
0 1 
Pop left in the deque 
The leftmost value is 0 
1 
```
## Other sources
Not using any other resource
