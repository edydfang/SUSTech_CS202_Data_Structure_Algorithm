# Problem B: Cuperman’s Queue

Time Limit: 1 Sec  Memory Limit: 128 MB

## Description

You have a queue with size n. Now there are m operations. Each operation will be one of the following cases:

Push x: If the queue is not full, push x into the queue. Otherwise print x.

Pop: If the queue has at least one element, print and pop the front element of the queue. Otherwise do nothing.

After the m operations, you should print all elements in the queue from the front.

Please write a program to print the elements in the order problem described.
Input

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
1 2
1 3
1 4
1 5
1 6
2
1 7
1 8
1 9
2
1 10
```

## Sample Output

```
6
1
8
9
2
3
4
5
7
10
```

## HINT

Easy problem