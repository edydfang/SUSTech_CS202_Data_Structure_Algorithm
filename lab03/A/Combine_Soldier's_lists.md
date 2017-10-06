# Problem A: Combine Soldier Lists

Time Limit: 1 Sec  Memory Limit: 128 MB

## Description

Cuperman has a machine which can travel among different planets. ItakEjgo used this machine and arrived the Linked List Planet. Linked List Planet was controlled by an evil guy “Huang Bo”, who raises hard problems to the island citizens, and forces them to write programs to solve. The planet citizens want to fight against Huang Bo. However, do that is not so easy, so they asked help from ItakeEjgo. The exact request is:

They have two branches of soldiers. In each branch, the soldiers are in an ordered (i.e., non-decreasing) list by their combat values. However, it only has one way to reach Huang Bo’s castle. Then, they need combine two soldier lists to one army list. They hope the army list is still ordered.

However, ItakEjgo do not know how to solve it by linked list. Fortunately, ItakEjgo knows that you are learning linked list in CS203. So ItakEjgo asks you for help!!! Each time, ItakEjgo will give you two ordered soldiers list, and you must return the army list to him after combination.

## Input

First line will be a positive integer T (T<=10), which is the number of messages.

For each message, the first line will be two integer n and m, which is the number of soldiers in the two branches. The second line will be the combat values of one branch. The third line will be the combat values of the other branch.

(1 <= n, m <= 10000, the combat values will in the range [0, 109])

## Output

For each message, prints the combat value of each solider in army list after combination.

## Sample Input

```
2
3 5
1 2 3
1 2 3 4 5
4 7
1 1 2 2
1 1 2 2 3 3 4
```

## Sample Output

```
1 1 2 2 3 3 4 5
1 1 1 1 2 2 2 2 3 3 4
```

## HINT

Easy Problem