# Problem E: Beautiful numbers

Time Limit: 1 Sec  Memory Limit: 128 MB

## Description

For the sequence {an}, let’s define the beautiful number of ai is j, where j is the minimum index with aj >ai and j > i. If no such j, the beautiful number of ai is 0. For each i in range [1, n], please output its corresponding beautiful number j.

## Input

The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

For each test case, the first line will be the integer n. (1 <= n <= 5*10^5)

Then there will n lines, and the ith line will have a number represent ai. (0 <= ai <= 10^5)

## Output

N lines for each test case. The beautiful number of ai

## Sample Input

```
1
6
3
2
6
1
1
2
```

## Sample Output

```
3
3
0
6
6
0
```

## HINT

Median problem