# Problem F: Minimum and Maximum

Time Limit: 1 Sec  Memory Limit: 128 MB

## Description

The problem is simple. Give you a sequence {a_n}, you should print the maximum and minimum value of every continuous subsequence of {a_n} with length k.
Input

The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

For each test case there will be two integers n and k. (1 <= n <= 5*10^5, 1 <= k <= n)

Then a line with n elements in the sequence {a_n}. ( 0 <= |a_i| <= 10^3)
Output

The output will contain two lines for each test case.

The first line will be n – k + 1 elements, the minimum value for each continuous subsequence with length k.

Then there is a line with n – k + 1 elements, the maximum value for each continuous subsequence with length k.

Print the answer of the subsequence in the same order with their first element appeared in {a_n}

(see details in the sample)

## Sample Input

```
1
5 3
1 3 2 5 4
```

## Sample Output

```
1 2 2
3 5 5
```

## HINT

Hard problem