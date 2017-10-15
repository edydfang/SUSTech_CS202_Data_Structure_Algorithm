# Problem A: Cuperman’s Stack

Time Limit: 1 Sec  Memory Limit: 128 MB

## Description

You have a stack with size n. Now there are m operations. Each operation will be one of the following cases:

Push x: If the stack is not full, push x into the stack. Otherwise print x.

Pop: If the stack has at least one element, print and pop the top element of the stack. Otherwise do nothing.

After the m operations, you should print all elements in the stack from the top.

Please write a program to print the elements in the order problem described.

# Input

The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

For each test case, the first line will be two integers n and m. (1 <= n <= 1000, 1 <= m <= 10^5)

Then there will be m lines, each line will be one of the following cases:

1 x: push x (0 <= x <= 10^5)

2: pop

## Output

Single line for each element, in the order problem required.

## Sample Input

```
1
5 12
1 1
2
1 2
1 3
1 4
2
1 5
1 6
1 7
2
2
1 8
```

## Sample Output

```
1
4
7
6
8
5
3
2
```

## HINT

Easy problem