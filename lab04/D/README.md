# Problem D: Magic Queue

Time Limit: 1 Sec  Memory Limit: 128 MB

## Description

After last lecture, you must know a lot of queue. Queue is a FIFO list. But do you know magic queue? Magic queue is a queue which supports four operations:

Push_frist x: push an element x from the front of the queue.

Pop_first: pop an element x from the queue.

Push_last x: push an element x at the rear of the queue.

Pop_last:pop an element x at the rear of the queue.

(See more in the samples)

Now there is a magic queue and n operations. Please write a program which can display the element in the queue after n operations.

## Input

The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

For each test case, the first line will be an integer n (1 <= n <= 10^5)

Then there will be n lines, each line will be one of the following cases:

1 1 x: push_first x

1 2: pop_first

2 1 x: push_last x

2 2:pop_last

(0 <= x <= 10^3)

The input ensures that when you pop, there always are some elements in the queue.

## Output

For each test case, print the elements in the magic queue from the front to the rear. And each element should in a single line.
## Sample Input

```
1
8
1 1 1
1 1 2
1 1 3
2 1 1
2 1 2
2 1 3
1 2
2 2
```

## Sample Output

```
2
1
1
2
```
## HINT

Median problem