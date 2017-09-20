# Common_problems

## Online Judge FAQ

### Mutiple input cases handling

#### Java

- class name: public class Main

```java
Scanner sc = new Scanner(System.in);
while(sc.hasNextInt())
// or  
while(sc.hasNext())
```

- 读一个整数： `int n = sc.nextInt();` 相当于 `scanf("%d", &n);` 或 `cin >> n;`
- 读一个字符串：`String s = sc.next();` 相当于 `scanf("%s", s);` 或 `cin >> s;`
- 读一个浮点数：`double t = sc.nextDouble();` 相当于 `scanf("%lf", &t);` 或 `cin >> t;`
- 读一整行： `String s = sc.nextLine();` 相当于 `gets(s);` 或 `cin.getline(...);`
- 判断是否有下一个输入可以用`sc.hasNext()`或`sc.hasNextInt()`或`sc.hasNextDouble()`或 `sc.hasNextLine()`

#### other language

reference: [http://acm.sustc.edu.cn/onlinejudge/faqs.php](http://acm.sustc.edu.cn/onlinejudge/faqs.php)

### Compile Error

- GCC的编译标准与VC6有些不同，更加符合c/c++标准:
- `main` 函数必须返回 `int`, `void main` 的函数声明会报编译错误。
- `i` 在循环外失去定义 `for(int i=0...){...}`
- `itoa` 不是 `ansi` 标准函数.
- `__int64` 不是 `ANSI` 标准定义，只能在 `VC` 使用, 但是可以使用 `long long` 声明64位整数。
- 如果用了 `__int64` ,试试提交前加一句 `#define __int64 long long`

### 系统返回信息都是什么意思?

- Wrong Answer : 答案不对，仅仅通过样例数据的测试并不一定是正确答案，一定还有你没想到的地方.
- Time Limit Exceeded : 运行超出时间限制，检查下是否有死循环，或者应该有更快的计算方法。
- Memory Limit Exceeded : 超出内存限制，数据可能需要压缩，检查内存是否有泄露。
- Output Limit Exceeded: 输出超过限制，你的输出比正确答案长了两倍.
- Runtime Error : 运行时错误，非法的内存访问，数组越界，指针漂移，调用禁用的系统函数。请点击后获得详细输出。
- Compile Error : 编译错误，请点击后获得编译器的详细输出。
- Pending : 系统忙，你的答案在排队等待.
- Pending Rejudge: 因为数据更新或其他原因，系统将重新判你的答案.
- Compiling : 正在编译.
- Running & Judging: 正在运行和判断.
- Accepted : 程序通过!
- Presentation Error : 答案基本正确，但是格式不对。

## Problem B Long Integer Sum

- 进位问题
- 最大位数
- 最终长度 `max{len(A), len(B)}` or  `max{len(A), len(B)} + 1` ?
- 实际测试样例为空格分割 `A` 与 `B`， 不能用 `nextLine` ?

## Problem C Cuperman’s Problem

- How to deal with the sapce between two cards

```
for card in cards:
    print card
    if card is not the last card:
        print ' '
    end
end
```
- How to deal with the RJ and BJ
```
when count, count as 4 cards
when print, break after one printing
Universal Algorithm + Tiny change
```

## Problem D Lucky Numbers

- Common mistake: enumerate from the least possible number to the largest possible number and test whether they are lucky number
**It is too slow because the number can be really huge (10^12)**
- We should generate the lucky number of possible length and test only those at the edge condition (临界情况).
- How to use recursion for the generation of the lucky number? From the middle.

## Problem E Count Points

- Some of students use brute force, ignoring how much the computation amount can be.
- Why we should use the GCD (Greatedt Common Divisor) Reference: [http://cleanbugs.com/item/poj2954triangle-for-the-entire-point-polygon-contains-the-entire-points-413551.html](http://cleanbugs.com/item/poj2954triangle-for-the-entire-point-polygon-contains-the-entire-points-413551.html)
- Also: Pick's theorem 皮克定理
- GCD Algorithm (Euclidean algorithm) 辗转相除法

## Problem F Cut Ropes for Lily (POJ 1064)

- Actually easy to think of the presedures
- Binary search for the largest length of pieces
- OJ answer actually has problem. They ignore the error caused when reading the number from the `stdin`, which is a process of **decimal to binary float**. For example, when read "5.74", the number stored in the variable may become "5.73999999". And when the algorithm test for the possible cuts, only the digits "5.73" are reserved. So all of the right answers to the test cases on OJ should have read the number by scanning the `float` from the input.
- Reference: https://www.zhihu.com/question/25457573

A special case is given here:

```
463 338
4.79 1.51 5.95 4.67 5.44 6.18 8.78 1.15 8.59 4.07 4.09 4.18 9.89 9.75 6.07 3.96 8.08 6.54 1.18 9.25 1.37 5.38 5.28 4.26 3.89 9.45 7.38 1.54 5.96 4.17 1.52 2.13 9.93 3.94 6.25 8.50 1.32 3.07 6.95 1.51 9.33 1.31 3.19 9.34 2.96 5.95 3.87 6.65 6.86 9.29 3.02 6.96 8.02 3.38 2.38 1.59 9.78 8.02 4.25 5.71 1.80 7.14 4.98 8.25 1.36 2.43 5.14 8.28 5.56 3.55 5.70 5.10 8.79 9.61 4.19 9.95 6.12 1.90 3.90 4.70 9.58 3.58 1.62 9.39 4.37 6.84 5.51 1.75 1.20 9.62 7.31 3.48 5.89 3.56 7.06 9.93 8.47 8.78 5.45 7.80 6.92 3.92 4.59 1.01 4.10 5.11 3.46 8.19 6.97 9.30 8.08 1.12 4.82 9.79 5.18 9.52 3.57 4.33 7.57 7.80 4.00 4.71 6.62 6.54 5.11 2.63 4.06 9.55 2.73 6.93 4.98 3.77 8.63 3.99 1.20 6.95 2.43 2.58 8.05 1.55 8.43 7.10 3.48 4.33 4.54 5.17 5.36 9.64 3.38 5.13 4.09 1.51 5.81 7.74 3.28 5.00 8.41 5.66 8.01 5.37 2.18 5.58 2.46 4.04 4.88 3.34 9.41 5.43 8.88 4.54 8.31 5.35 6.05 7.58 1.95 5.73 3.74 2.38 6.61 7.82 1.60 8.29 3.28 1.74 1.02 9.08 9.69 9.69 3.27 4.71 6.58 4.76 9.74 2.33 1.42 3.11 8.09 2.36 1.78 3.45 7.35 9.56 6.26 7.18 4.61 1.39 1.67 6.10 7.18 2.95 1.38 1.75 1.34 5.59 1.38 4.25 2.54 4.71 2.23 2.48 1.67 6.19 5.54 9.26 9.51 8.28 9.28 7.47 5.70 8.62 8.29 7.29 6.24 2.93 2.92 9.21 2.00 7.90 9.90 6.48 5.68 5.46 4.42 3.42 8.78 4.88 7.80 3.39 6.33 5.43 4.33 1.03 6.54 8.56 4.97 8.18 9.62 7.62 6.64 3.17 2.67 6.00 9.22 8.82 1.29 8.32 3.93 9.35 3.62 9.81 7.81 1.94 3.35 2.00 5.27 7.41 7.87 7.34 7.48 2.65 3.57 9.04 6.58 5.13 5.52 7.36 4.12 5.01 6.78 2.99 3.79 4.70 4.40 2.54 1.35 2.74 1.82 6.86 3.52 9.61 6.37 1.18 6.59 5.70 5.60 5.77 1.81 2.15 8.37 4.58 9.19 1.45 5.72 5.76 3.49 4.25 8.51 9.37 7.77 5.26 4.39 9.09 9.90 1.47 7.40 9.41 9.40 1.04 2.79 2.65 1.11 1.03 2.28 9.62 7.87 1.07 7.87 6.85 2.88 6.86 6.78 4.04 2.22 6.47 4.03 3.72 2.48 5.56 7.30 3.20 6.11 7.68 7.39 3.14 2.26 2.81 2.76 8.30 8.32 7.99 8.32 2.38 4.54 2.64 6.17 2.34 7.98 6.40 3.54 8.56 2.46 5.04 8.75 3.07 8.53 5.98 7.35 3.12 8.73 4.03 1.05 4.79 8.59 2.49 8.40 7.62 2.68 6.41 4.72 1.01 7.44 1.66 4.05 4.89 4.75 8.62 2.46 9.34 1.26 3.11 4.52 1.66 2.31 2.52 7.42 8.75 8.09 1.90 5.98 3.72 2.71 3.35 3.47 3.67 9.63 4.40 2.98 6.13 1.00 8.77 3.70 8.09 3.11 1.06 3.87 5.32 4.93 5.34 9.46 3.21 6.73 3.36 4.73 2.27 9.88 8.49 8.79 4.61 9.11 3.42 5.58 7.62 4.21 5.75 6.62 6.35 7.80 9.13 6.66 8.53 4.48 9.14 4.44 3.78 7.47 1.03 8.05 7.97 7.06 6.32 8.96 9.83 3.76
```

They right answer should be `4.39`, but the answer in OJ is `4.38`

```
8.78 => 8.7799999
1.15 => 1.1499999
...
```
