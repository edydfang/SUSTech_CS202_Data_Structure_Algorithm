# Problem E: Hash the string!

Time Limit: 1 Sec  Memory Limit: 128 MB

## Description

Do you know how to hash a string? Normally we represent a string in an integer. Then we can transfer from dealing with strings to dealing with integers, which is more convenient. A popular way of hashing a string is:S_{hash}=∑(|S_{0,i}|*cnt(S_{0,i})). where S_{hash} is an integer, which is the hash value. S_{0,i} is the substring of S from position 0 to position i. cnt(S_{0,i}) is how many times S_{0,i} appears in S. Now give you a string S, please calculate the hashed value Shash.

## Input

The first line will be an integer T, which is the number of test case. (1 <= T <= 10)

The first line for each test case will be an integer n, which is the length of string S.

Then there is a line with string S. |S| <= 1000000

S will only contain lower case English letters.

## Output

Print an integer for each test case, the hashed value.

## Sample Input

```
1
3
aaa
```

## Sample Output

```
10
```

## HINT

Hard problem.