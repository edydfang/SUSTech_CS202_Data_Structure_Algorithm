### Problem E: Monopoly

Time Limit: 1 Sec  Memory Limit: 128 MB

#### Description

Monopoly is a very popular game, ItakEjgo likes it. Now we will play a simple Monopoly game. There are N houses in a ring, labeled as 0, 1 … N – 1. These houses belong to N different people and the ith house has an income a[i] and a fortune f[i]. At first, f[i] = 1 for i ∈ [0, N-1]. ItakEjgo moves K steps from house X. For each move step, he can only move from house i to house i + 1, or from house N – 1 to house 0. If he comes to the ith house, he will give some money to the person who owns this house and `his` (the owner) fortune will become a[i] * f[i]. After K moves, these N people want to know how much money they get. Please notice that ItakEjgo comes to house X also need 1 move step.

#### Input

The first line will be an integer T (0 <= T <= 100), which is the number of test cases.

For each test case:

The first line will be 3 integers: N (1<= N <= 1000), K (0 <= K <= 10^9), X (0 <= X < N).

Then will be N numbers, the ith number represent the income a[i]. (0 <= a[i] <= 10^9)

#### Output

For each test case, you should output N numbers. 

The ith number should be the fortune of the ith person f[i] module 123456789.  (i.e., f[i] % 123456789)

#### Sample Input

```
2
3 2 1
3 3 3
5 7 2
1 2 3 4 5
```

#### Sample Output

```
1 3 3
1 2 9 16 5
```

#### HINT

Median Problem
