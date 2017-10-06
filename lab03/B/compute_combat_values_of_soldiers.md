# Problem B: Compute Combat Values of Soldiers

Time Limit: 2 Sec  Memory Limit: 128 MB

## Description

With your help, the army list attacked Huang Bo’s castle several times, however, Huang Bo always win these wars. Then, the army master wants to know the combat values of among different soldiers.

As you may know, it has different solider levels in this plant, e.g., level 1 is (x), level 2 is (x^2), …, level n is (x^n). The combat value of soldiers in each branch can be represented by `polynomial with level char x`. For example, one soldier branch is f(x) = x+x^2+2x^3, the other solider branch is g(x) = x^2. The total combat values of soldiers in this planet is defined as addition among two polynomials. In above example, the total combat values of soldiers are h(x)= x+2x^2+2x^3. ItakEjgo asks you for help as he is not good at math. Each time, ItakEjgo will give you the `(coefficient, exponent)` pairs (i.e., in ascending order of soldiers level) of two polynomials. For example, f(x) = 1+2x+3x^2 will be given as (1 0), (2 1), (3 2). You return the polynomial after addition to him. Since the soldiers may be injured in the war, so the coefficients could be negative values.

Note that, to help army master to understand:

**Please pay attention to the special cases, e.g., the result is 0, the sum of compact values is 0 or 1 at level i. We follow all these definitions and notations in Math.**

## Input

First line will be a positive integer T (T<=100), which is the number of messages.

The first line will be an integer n, which is the number of terms of the first polynomial. Then n lines will be the coefficients and exponents of the terms.

After n + 1 lines, there will be an integer m for the number of terms of the second polynomial. And m lines of (coefficient, exponent) pairs.

(0 <= n, m <= 1000, all exponents are in the range [0, 10^9], all coefficients are in the range [-10000, 10000])

## Output

For each message, print the polynomial with the same syntax as the sample shows.

## Sample Input

```
1
2
2 2
3 3
2
1 2
2 4
```

## Sample Output

```
3x^2+3x^3+2x^4
```

## HINT

Median problem