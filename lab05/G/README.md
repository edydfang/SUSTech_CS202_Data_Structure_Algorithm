# Problem G: Presuffix

Time Limit: 1 Sec  Memory Limit: 128 MB

## Description

As we defined in problem E. A prefix of a string S is S0,i, similarly, a suffix of a string S is Si,|s|-1.

If a substring of S is both a prefix and suffix, we defined the substring is a presuffix. Now give you a string S, please print all presuffix.
Input

The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

For each test case, there will be a line with an integer n, which is the length of the string.

Then there is a line with a string S. |S| <= 100000.

S will only contain lower case English letters.

## Output

Several lines for each test case. All presuffix of S. And each presuffix should in a single line.

There is en empty line between each test case (Including the last test case).

Print all presuffix by their length in ascending order.

## Sample Input

```
2
5
abaab
5
aaaaa
```

## Sample Output

```
ab
abaab

a
aa
aaa
aaaa
aaaaa
```

## HINT

Bonus problem