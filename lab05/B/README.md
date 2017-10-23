# Problem B: String operations

Time Limit: 1 Sec  Memory Limit: 128 MB

## Description

As you know, string has several operations:

1. Add x pos: add char x to the position pos.

2. Delete pos: delete char at the position pos.

3. Sstr x y: print the substring of s from position x to y (don’t change origin string s).

4. Reverse x y: reverse the char from position x to y

Now give you a string S and n operations, please output the result after each operation.

The string begins with index 0.

## Input

The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

The second line is a string S. |S| <= 1000. S will contain both upper case and lowercase English letters.

The third line will be an integer n (1 <= n <= 40). Then n operations:

Add x pos

Delete pos

Sstr x y

Reverse x y

Where x, y and pos are integers. The input ensures all operations are legal, and x <= y. 

## Output

N strings for each test case, the result after each operations.

## Sample Input

```
1
HiMadamIMAdam
6
Sstr 2 12
Delete 0
Delete 0
Reverse 0 10
Add M 0
Delete 1
```

## Sample Output

```
MadamIMAdam
iMadamIMAdam
MadamIMAdam
madAMImadaM
MmadAMImadaM
MadAMImadaM
```

## HINT

Easy problem.