# Problem F: Cut Ropes for Lily (POJ 1064)

Time Limit: 2 Sec  Memory Limit: 128 MB

## Description

Lily asked Huang Bo: “We have n ropes at hand, and we want to cut them into some pieces. And we also want to get at least k ropes with the same length. Can you give me the answer of the longest length of these k ropes?” Huang Bo thought for a while and said that we can sort the ropes by their length in descending order, and the kth biggest length is the answer. Lily said: “No, you are wrong”. Lily is unhappy with Huang Bo’s answer, and Huang Bo is in trouble, can you help him?

## Input

There are multiple test cases (less than 1000). For each test case, the first line will be two integers n and k (0 <= n <= 1000, 0 <= k <= 10000), the second line will be n floating numbers and the ith number is the length of i-th ropes, denoted as `ai` (0 <= `ai` <= 100000). And all lengths in the input file are written with a centimeter precision, with exactly two digits after a decimal point.

## Output

One floating number the longest length of these k ropes for each test case. Please notice that the number must be written with exactly two digits after decimal point.

## Sample Input

```
4 8
2.00 2.00 2.00 2.00
4 8
1.71 2.32 6.33 8.00
```

## Sample Output

```
1.00
2.00
```

## HINT

Bonus problem. Binary search. Try to avoid doing binary search in floating numbers and pay attention to 0.