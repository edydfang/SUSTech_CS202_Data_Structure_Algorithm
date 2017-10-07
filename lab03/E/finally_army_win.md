# Problem E: Finally, Army win!

Time Limit: 2 Sec  Memory Limit: 256 MB

## Description

With the help of you, ItakEjgo finally find out the spy, and reach the castle where Huang Bo lives with the army list and special group.

Huang Bo: How can you arrive here? Why my spy didn’t send any message to me?

ItakEjgo: It’s not important. Today you will die here, and the people in the Linked List Planet don’t need to program anymore!

Huang Bo: Too young too naive! Do you know why I can dominate the Planet? Because I have a special weapon, Zangetsu!


Since the Zangetsu is very powerful, ItakEjgo and the soldier are going to lose. But suddenly, Cuperman comes out and gives ItakEjgo a new weapon. Cuperman tells ItakEjgo that: ” This weapon must be used by two armies at the same time. With this new weapon, the total combat value of the army list will be `the multiplication of the combat value of the two armies`. By using this, you can defeat Huang Bo and save all planet citizens!”

Finally, Huang Bo lost the war. The people in the Linked List Planet live a happy life! Cuperman and ItakEjgo go back to earth by taking the machine. After they arrived at the earth, ItakEjgo still wants to know what the total combat value of two soldier list is. Since ItakEjgo is not good at math, so he asked your help again.

## Input

First line will be a positive integer T (T<=10), which is the number of messages.

The first line will be an integer n, which is the number of terms of the first polynomial. Then n lines will be the (coefficient, exponent) pairs.

After n + 1 lines, there will be an integer m for the number of terms of the second polynomial. And m lines of the (coefficient, exponent) pairs.

(1 <= n, m <= 100, all coefficients are in the range [1, 10000], all exponents are in the range [1,10^9])

## Output

For each message, print the polynomial with the same syntax as the sample shows.

## Sample Input

```
1
2
1 1
1 2
2
1 1
1 2
```

## Sample Output

```
x^2+2x^3+x^4
```

## HINT

Median problem