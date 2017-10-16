# Problem C: Brackets Matching

Time Limit: 1 Sec  Memory Limit: 128 MB

## Description

There are n brackets. And you want to know whether they are match to each other. The brackets will only contain {, }, (, ), [, ]. The matching rules are the same as in Math. For example, {{[}]} is not matching, and [{{}}()] is matching. Please write a program to check whether the given brackets string is matching or not.

## Input

The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

For each test case, the first line will be an integer n ( 1 <= n <= 30000)

Then there is a line with n brackets.

## Output

For each test case, print YES if the test case is a matching case. Otherwise, print NO.

## Sample Input

```
7
1
(
2
()
2
{]
6
[(){}]
4
(])[
8
[[{{}}]]
6
[][{]]
```

## Sample Output

```
NO
YES
NO
YES
NO
YES
NO
```

## HINT

Easy problem