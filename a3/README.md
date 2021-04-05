# Assignent 3

## Intructions to run (for all parts, unless stated otherwise):
To run part `<x>` of the assignment, just do : ```lex <x>.l && cc lex.yy.c -lfl && ./a.out```.

So part a can be run as: ```lex a.l && cc lex.yy.c -lfl && ./a.out```.

## Q: A
### Note: 
- Input will be taken from file ```input_a.txt```
- Output will be stored in a file ```output_a.txt```

## Q: B
### Note: 
- Input will be taken from file ```input_b.txt```
- Output will be stored in a file ```output_b.txt```

## Q: C
### Note: 
- Input will be taken from file ```input_c.txt```
- Tokens and number of tokens will be printed on STDOUT.

## Q: D
### Note: 
- Input will be taken from file ```input_d.txt```
- Output will be printed on STDOUT.
### Important:
- If you edit input_d.txt in modern text editors such as VS code, you might get incorrect results (since they convert tabs to spaces). Please edit in nano or vim if you wish to edit this file.

## Q: E
### Note: 
- Input will be taken from STDIN, press enter (newline) to submit.
- Output will be printed on STDOUT.
- Sample input ```hello world```
### Assumptions:
- Words are be made up of alphabets only and seperated by spaces (anything failing this criteria will not be counted)
- If you enter (say) "123wqer45", it will not be counted as a word.
- aBc is a valid word. (case doesn't matter)

## Q: F
### Note: 
- Input will be taken from STDIN, press enter (newline) to submit.
- Output will be printed on STDOUT.
- Sample input ```hellow world```
### Assumptions:
- Words are be made up of alphabets only and seperated by spaces (anything failing this criteria will not be counted)
- If you enter (say) "123wqer45", it will not be counted as a word.
- aBc is a valid word. (case doesn't matter)


## Q: G
### Note: 
- Input will be taken from STDIN, press enter (newline) to submit.
- Output will be printed on STDOUT.
- Sample input ```hello world```

## Q: H
### Note: 
- The word that has to be searched will be taken from STDIN, press enter (newline) to submit.
- The program will check if the given word is present in file ```input_h.txt```
- Output (Found/Not Found) will be printed on STDOUT.


## Q: I
### Note: 
- Input will be taken from STDIN, press enter (newline) to submit.
- Output will be printed on STDOUT.
### Assumptions:
- Words are be made up of alphabets only and seperated by spaces (anything failing this criteria will not be counted)
- If you enter (say) "123wqer45", it will not be counted as a word hence won't contribute to finding the longest word.
- aBc is a valid word, but it is not same as abc.

## Q: J
### Note: 
- Input will be taken from file ```input_j.txt```
- The word to be checked is present in ```line 5``` of the file ```j.l```.
- Output will be printed on STDOUT.
### Assumptions:
- Words are be made up of alphabets only and seperated by spaces (anything failing this criteria will not be counted as a word)
- aBc is a valid word, but it is not same as abc.

## Q: K
### Note: 
- Input will be taken from STDIN, press enter (newline) to submit.
- Output will be printed on STDOUT.
### Assumptions:
- Numbers will be seperated by spaces (anything failing this criteria will not be counted)

## Q: L
### Note: 
- Input will be taken from STDIN, press enter (newline) to submit.
- Output will be printed on STDOUT.
### Assumptions:
- Numbers will be seperated by spaces (anything failing this criteria will not be counted)
- Numbers can be integers or fractions
- A sample input is: ```1 +2 -34 +0.9 -1 -3 -34 -3.7 +4.4 1.1```

## Q: M
### Instructions to compile and run:
```lex m.l && cc lex.yy.c -lfl -lm && ./a.out```
### Note: 
- Input will be taken from STDIN, press enter (newline) to submit.
- Output will be printed on STDOUT.
### Assumptions:
- Only one number is given as input.
- Number will fit in "long"

## Q: N
### Note: 
- Input will be taken from STDIN, press enter (newline) to submit.
- Output will be printed on STDOUT.
### Assumptions:
- Only one number is given as input.

## Q: O
### Instructions to compile and run:
```lex o.l && cc lex.yy.c -lfl -lm && ./a.out```
### Note: 
- Input will be taken from STDIN, press enter (newline) to submit.
- Output will be printed on STDOUT.
### Assumptions:
- Only one number is given as input.
- Number will fit in "long"

## Q: P
### Note: 
- Input will be taken from STDIN, press enter (newline) to submit.
- Output will be printed on STDOUT.
### Assumptions:
- Only one number is given as input.

## Q: Q
### Note: 
- Input will be taken from STDIN, press enter (newline) to submit.
- Output will be printed on STDOUT.
### Assumptions:
- Only one email is given as input.

## Q: R
### Note: 
- Input will be taken from STDIN, press enter (newline) to submit.
- Output will be printed on STDOUT.
### Assumptions:
- Only one IP address is given as input.
- A valid IP is a form ```a.b.c.d``` where a, b, c, d are integers in the range [0-255]

## Q: S
### Note: 
- Input will be taken from file ```input_s.txt```
- Output will be stored in a file ```output_s.txt```

## Q: T
### Note: 
- Input will be taken from file ```input_t.txt```
- Output will be stored in a file ```output_t.txt```