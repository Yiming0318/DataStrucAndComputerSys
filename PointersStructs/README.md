## Info
```

Yiming Ge

Tricky Part: given struc Name's first middle and last 
are all read only string instead of string array
```

## Description & Summary
```

I wrote detailed comments in the code file.
The main point of this assignment is to deal with pointer.
if the user gives a wrong format, "wrong format" will print out in the console.


The hard part is the bonus question.
We need to use heap memory to convert the Name into leagal form:
the first letter is capitalized and the remaining letters are in small cases.
```

## Test Output
```

Test #1: Print Big

Alyssa Mary Antle

Ben Ivan Bitdiddle

Daniel Diamond


--------------------------------

Test #2: Print Last

Bitdiddle, Ben

Diamond, Daniel


--------------------------------

Test #3: Print Reg

Cassie Charstrup

Daniel Diamond


--------------------------------

Test #4: Print Mid

Daniel Diamond

Alyssa M. Antle


--------------------------------

Test #5: Print Small

Daniel

Ben


--------------------------------

Test #6: Print FormatName

Alyssa Mary Antle

Antle, Alyssa

Alyssa Antle

Alyssa M. Antle

Alyssa

Daniel Diamond

Diamond, Daniel

Daniel Diamond

Daniel Diamond

Daniel


--------------------------------

Test #7: Print FillName

Alyssa Mary Antle
Antle, Alyssa
Ben I. Bitdiddle
Anya
wrong format

--------------------------------

feel free to add your own!
```



## UsedExternalFunctions
<ctype.h> Functions
The tolower() function takes an uppercase alphabet and convert it to a lowercasecharacter.
The toupper() function converts a lowercase alphabet to an uppercase alphabet.


## LinksToReference
[How to copy paste and move file in terminal](https://support.apple.com/en-in/guide/terminal/apddfb31307-3e90-432f-8aa7-7cbc05db27f7/mac)

[Output Char in C](https://stackoverflow.com/questions/310032/output-single-character-in-c#:~:text=yes%2C%20%25c%20will%20print%20a,c%22%2C%20'h')%3B)

[Char Comparison](https://stackoverflow.com/questions/22736348/char-comparison-in-c/22736489)

[Concatenate two strings](https://stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c/8465083)

[Difference between strlen() & sizeof()](https://www.geeksforgeeks.org/difference-strlen-sizeof-string-c-reviewed/)

[Convert char to string](https://www.quora.com/How-do-I-convert-a-char-to-string-in-C)

[Difference between strlen() and sizeof() for string in C](https://www.geeksforgeeks.org/difference-strlen-sizeof-string-c-reviewed/)

[pinpointing "conditional jump or move depends on uninitialized value(s)" valgrind message](
https://stackoverflow.com/questions/2612447/pinpointing-conditional-jump-or-move-depends-on-uninitialized-values-valgrin)

[How do I lowercase a string in C](https://stackoverflow.com/questions/2661766/how-do-i-lowercase-a-string-in-c)

[Different ways to copy a string in C](https://www.geeksforgeeks.org/different-ways-to-copy-a-string-in-c-c/)

[snprintf for string concatenation](https://stackoverflow.com/questions/12065286/snprintf-for-string-concatenation/12065309)
