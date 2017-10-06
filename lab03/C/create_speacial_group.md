# Problem C: Create Special Group

Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 11  Solved: 2
[Submit][Status][Web Board]
Description

Congratulation! You helped ItakEjgo solved two problems!

 

Before attack Huang Bo again, the army master created a special group. The combat value of soldiers in the special group list are random. The army master has four basic instructions in the special group: 1) Insert (x, y), 2) Delete(x), 3) Update(x,y), and 4) Reverse. The means of these instructions are:

Insert(x,y): insert soldier with combat value y at position x.

Delete(x): remove soldier at position x

Update(x,y): set combat value of soldier at position x as y.

Reverse: reverse the soldiers’ combat value in the special group list.

For example, suppose we have special group list {1,3,2,4}, position is starting from 0.

Insert (0,5) will change the special group list to {5,1,3,2,4}

Delete(3) will change the special group list to {5,1,3,4}

Update(1,7) will change the special group list to {5,7,3,4}

Reverse will change the special group list to {4,3,7,5}

 

Given a special group list, and a set of instructions, could you print the special group list to ItakEjgo after each instruction? For simplicity, Insert is 1, Delete is 2, Update is 3 and Reverse is 4 in the input.
Input

First line will be a positive integer T (T<=50), which is the number of messages.

For each message, the first line will be two integer n and m, n is the number of soldiers at first. M is the number of operations. Then will be n integers which are the combat value of soldiers.

Then will be m lines, each is a command:

1 x y : insert soldier with combat value y at position x.

2 x: remove the soldiers at position x

3 x y: set combat value of soldier at position x as y.

4: reverse the army

The input guarantee that the army will not be empty during the operation.

(1 <= n, m <= 100, all labels will be in range [0, 1233])
Output

For each test case, output the special group after each instruction.
Sample Input

1
4
1 3 2 4
4
1 0 5
2 3
3 1 7
4
Sample Output

5 1 3 2 4
5 1 3 4
5 7 3 4
4 3 7 5
HINT

Easy problem