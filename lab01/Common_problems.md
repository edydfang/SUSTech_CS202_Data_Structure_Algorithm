# Common_problems

## Online Judge

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