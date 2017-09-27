### Problem G: Find Score X in Lab 1 CS203

Time Limit: 1 Sec  Memory Limit: 128 MB

#### Description

In CS203 lab 1, OJ sorted the scores of Group 3 students in ascending order in array `S`.

Cuperman wants to know the first position of a given score `X`, could you help him?

#### Input

Standard input will contain multiple test cases. The first line of the input is a single integer `T` (`1 <= T <= 10`) which is the number of test cases.

T test cases follow, for each test case:

The first line contains an integer `N` (`1 <= N <= 10^4`)

The second line contains N integers, which are sorted scores `{S[1], S[2], S[3], …, S[n]}`. where `0 <= S[i] <= 10^9` .

Then a single line with an integer `Q` (`0 <= Q <= 10^4`)

Then there will be `Q` lines. Each line will give an integer `x`.

#### Output

For each query, output the first position `i` in array `S` such that `S[i]` = `X`, if `X` is not in the array `S`, output `-1`.

#### Sample Input

```
1
6
1 2 2 4 5 6
2
2
7
```

#### Sample Output

```
2
-1
```

#### HINT

Bonus Median