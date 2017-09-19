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

## Problem B (Long Integer Sum)

- 
