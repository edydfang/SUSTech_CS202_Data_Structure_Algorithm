# Cuperman’s Problem

## Description

Doudizhu is a very popular poker card game. It has three players, two of them are Farmers, Farmer has 17 cards and the third player is Dizhu, Dizhu has 20 cards. Cuperman likes Doudizhu, but he is lazy, he does not want to sort cards in his hand. One day, when he is playing Doudizhu with Lucy and Lily, he asked Huang Bo to sort his cards by the following order: Red joker > White joker > 2 > A > K > Q > J > 10 > 9 > 8 > 7 > 6 > 5 > 4 >3. For example, if he not a Dizhu, he has Red joker, four K, three 2, four 9, one A, two 6, two 5, the order will be
`Red joker K K K K 9 9 9 9 2 2 2 6 6 5 5 A`
As we all know, Huang Bo is TA of CS203, he asks the students in his course to help him.

## Input

There are multiple test cases (less than 20), for each case, you will be given a string in the first line show whether Cuperman is a Farmer or Dizhu.
Next line contains either 17 or 20 cards, i.e., the cards in Cuperman’s hand.(Red joker will be RJ, and Black joker will be BJ).

## Output

One line for each test case, give the cards in order according to the problem.
Please notice that there are no space in the end of line.

## Sample input

> Farmer
> RJ K 2 2 K K K 2 9 9 A 6 6 5 5 9 9
> Dizhu
> WJ RJ 9 8 K Q Q 4 3 8 5 4 3 8 K 6 J J 7 A

## Sample output

> RJ K K K K A 2 2 2 9 9 9 9 6 6 5 5
> RJ WJ A K K Q Q J J 9 7 8 8 8 6 5 4 4 3 3
