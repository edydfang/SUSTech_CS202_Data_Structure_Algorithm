# Problem F: Old Text Editor

Time Limit: 1 Sec  Memory Limit: 128 MB

## Description

After ItakEjgo wrote the problem description, Dr. Tang found out many mistakes. So he asked ItakEjgo to correct his mistakes. But ItakEjgo only has an old machine. The machine has two operations:

Insert(ch, p), insert the char ch to position p.

LookUp(p), look up the char at position p and print it to screen.

ItakEjgo wants you to help him. He will give you a description with many mistakes and several operations. Please follow the operations by using the old machine.

## Input

The first line will be an integer T (1 <= T <= 10), which is the number of test cases.

For each test case, the first line will be a string S, which is the description with mistakes. And the description is in lower case English letters. The second line will be an integer n, which is the number of operations. Then there will be n lines operations. To simplify the problem, 1 will represent Insert and 2 will represent Lookup.

(The length of a string <= 10^6, the number of operations <= 1000)

## Output

For each test case, follow the operation the problem gives.

## Sample Input

```
1
madamimadam
4
1 h 1
1 h 2
2 3
2 2
```

## Sample Output

```
m
h
```

## HINT

Hard problem