### Problem C: Index Twin

Time Limit: 1 Sec  Memory Limit: 128 MB

#### Description

Given an sorted `ascending` integer array A and a specific target m. Cuperman defines (i,j) is index twin if A[i] + A[j] = m. Could you help Cuperman to find how many index twins are in the given array A with a specific target m.
Input
so
The first line will be an integer T(1<T<=10), which is the number of test cases.

For each case contain two lines.The first line contains two numbers n(1<=n<=5000) and m(1<=m<=108), n is the size of array A. m is the specified target.

The second line contains n integers: a1, a2, ... an (1<=ai <= 10^6, 1 <= i <= n).
Sorted?

#### Output

For each case print a number, the number of index twins.

#### Sample Input

```
3
4 5
1 2 3 4
4 9
2 7 11 15
3 6
1 2 3
```

#### Sample Output

```
2
1
0
```

#### HINT

Easy Problem.