# Finding Group Anagrams with Hashtables
Yiming Ge

General Idea: Use Key to store the sorted word and use value to store a list of anagrams in the Hashtable
python easy code (same logic as this c homework):
```
from collections import defaultdict
hashtable = defaultdict(list)
words_collection = ['abc', 'cba', 'acb', 'dd', 'ee']
for word in words_collection:
    sorted_word = ''.join(sorted(word))
    if sorted_word in hashtable:
       hashtable[sorted_word].append(word)
    else:
       hashtable[sorted_word].append(word)
print(hashtable)
```
```
** using make test to complie smallwords test file
run ./test
output:
Bucket 0: 
key: bb value: [bb],
Bucket 1: 
key: ccp    value: [pcc,cpc,ccp],
Bucket 2: 
key: def    value: [efd,fed,def],
Bucket 3: NULL
Bucket 4: 
key: aertw  value: [terwa,water],
Bucket 5: 
key: cc value: [cc],
key: aa value: [aa],
Bucket 6: NULL
Bucket 7: NULL
Bucket 8: 
key: abc    value: [acb,cba,abc],
Bucket 9: NULL


** using make run to run the whole program (using the words.txt) 
You can change the bucket number in the main functions
The smaller the bucket number the more the collisions
```

# How Long it takes me
Many many hours, waste tons of time on start code. Try to figure out how to
implement the hashmap with key and value with char and list type.

# Other resources
```
https://www.tutorialspoint.com/c_standard_library/c_function_strcspn.htm
https://www.faceprep.in/c/program-to-sort-a-string-in-alphabetical-order/
https://en.wikipedia.org/wiki/List_of_prime_numbers
https://stackoverflow.com/questions/7666509/hash-function-for-string
https://www.zhihu.com/question/266414962
GeeksforGeek, bilibili, CSDN
```


