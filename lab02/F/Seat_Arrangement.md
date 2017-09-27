### Problem F: CS203 Seat Arrangement

Time Limit: 1 Sec  Memory Limit: 128 MB

#### Description

In the CS203 midterm examination, Dr. Tang requires `K` students to sit in a row. However, it only has `N` available seats in that row, at positions seat[1], seat[2], …, seat[n]. To prevent cheating, Dr. Tang wants to assign the students to these available seats, such that the minimum distance between any two adjacent students is as large as possible. Could you tell him what is the `largest minimum distance`?


#### Input

Standard input will contain multiple test cases. The first line of the input is a single integer `T` (1 <= `T` <= 10) which is the number of test cases.

T test cases follow, for each test case:

The first line contains two integers N and K (2 <= `K` <= `N` <= 100000)

The second line contains `N` integers, which are the positions of available seats, i.e., the i-th integer is the position of seat[i] \(0 <= seat[i] <= 10^9\).

#### Output

Each test case prints a single line. The largest minimum distance between any two adjacent students.

#### Sample Input

```
2
7 7
1 2 3 4 5 6 7
3 2
1 4 7
```

#### Sample Output

```
1
6
```

#### HINT

Hard Problem.