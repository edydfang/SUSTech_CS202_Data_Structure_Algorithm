# Problem D: Abracadabra

Time Limit: 1 Sec  Memory Limit: 128 MB

## Description

Do you believe in Magic? There is a magic abracadabra which can let you get AC to all problems in CS203 Lab5. But the abracadabra has some useless word. Give you the abracadabra S and a useless word T. Please print the abracadabra after delete all useless word. And pay attention to that you should remove the word from left to the right. That is, if we remove bab from babab , the result is ab.

## Input

The first line is the number of test cases T. (1 <= T <= 10)

The second line is the length of abracadabra, n.

Then there is a line with a string S, which is the abracadabra. |S| <= 1000000

The third line will be an integer m, the length of the useless word.

Then there is a line with a string T, which is the useless word T. |T| <= |S|

S and T will only contain lower case English letters.

## Output

Print a string in a single line. The result problem required.

## Sample Input

```
1
29
yourshahawehaatwillhanotlieha
2
ha
```

## Sample Output

```
yoursweatwillnotlie
```

## HINT

Median problem.