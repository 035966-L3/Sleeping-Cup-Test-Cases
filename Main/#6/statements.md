## 一、基础知识（共 15 小题，每小题 2 分，满分 30 分）
### （一）语言入门
1. 网络分局域网，广域网等。下列不属于网络的是（$\qquad$）。
{{ select(1) }}
-  LAN
-  MAN
-  NAN
-  WAN

2. 下列文件不是 C++ 源代码的是（$\qquad$）。
{{ select(2) }}
-  `1.c`
-  `2.cc`
-  `3.c++`
-  `4.cpp`

3. 在 2022 年，CCF 系列比赛的 C++ 版本是（$\qquad$）。
{{ select(3) }}
-  C++11
-  C++14
-  C++17
-  C++20

### （二）逻辑推理
4. 在无符号 $8$ 位整数运算下，C++ 中 `15 & 26 + ~ 8 << 2` 的结果为（$\qquad$）。
{{ select(4) }}
-  $1$
-  $2$
-  $4$
-  $8$

5. 已知 $\lnot A \land B \lor C = B \land C \oplus (B \lor C) \oplus \lnot A = \texttt{true}$，则 $A,B,C$ 中 $\texttt{true}$ 的个数为（$\qquad$）。
{{ select(5) }}
-  $0$
-  $1$
-  $2$
-  $3$

6. 已知 $N$ 个有标号有权点被若干条不重复的无向边连成一棵树。定义一条边的边权为其两个端点的点权之和，设 $N$ 个点的点权和为 $S$，点权中的最小值为 $T$，则该树的边权和最小为（$\qquad$）。
{{ select(6) }}
-  $S + (N - 2)T$
-  $S + NT$
-  $2S + (N - 2)T$
-  $2S + NT$

### （三）轻松图论
7. $3$ 个点的有向图（没有重边自环，允许 $a \to b$ 和 $b \to a$ 同时存在）最多有（$\qquad$）条边。
{{ select(7) }}
-  $3$
-  $4$
-  $5$
-  $6$

8. $4$ 个点的无标号二叉树共（$\qquad$）棵。
{{ select(8) }}
-  $1$
-  $2$
-  $5$
-  $14$

9. 下面这棵二叉树的中序遍历是（$\qquad$）。

   | 结点 | 左儿子 | 右儿子 |
   | :--: | :--: | :--: |
   | $1$ | $/$ | $/$ |
   | $2$ | $1$ | $3$ |
   | $3$ | $/$ | $/$ |
   | $4$ | $2$ | $6$ |
   | $5$ | $/$ | $/$ |
   | $6$ | $5$ | $7$ |
   | $7$ | $/$ | $/$ |
   
{{ select(9) }}
-  `1234567`
-  `4213657`
-  `1325764`
-  `4261357`

### （四）数据结构
> 我们知道，顺序表和链表各有优劣。现在，我们考虑将 $n$ 个数据均分成约 $\sqrt{n}$ 组，每组用链表串成一串，再用顺序表维护这 $\sqrt{n}$ 串数据，这便是「块状链表」了。假设某块状链表含 $n$ 个数据，**请完成下面三个问题**：
10. 查询位于指定位置的一个元素，大约需要访问（$\qquad$）个元素。
{{ select(10) }}
-  $1$
-  $\sqrt{n}$
-  $n$
-  $n \sqrt{n}$

11. 插入一个元素到指定位置后面，大约需要访问（$\qquad$）个元素。
{{ select(11) }}
-  $1$
-  $\sqrt{n}$
-  $n$
-  $n \sqrt{n}$

12.  按以下算法给所有元素排序：
      
      - 对每个串进行冒泡排序。
      - 对 $\sqrt{n}$ 个串一起选择排序。

     以比较、访问、交换和赋值为基本单位，则大约要运算（$\qquad$）次。
     > **提示：**
     > 
     > 冒泡排序时，交换两个元素，只需将第一个元素删除，再重新插入到第二个元素后面即可。
     > 
     > 选择排序时，可以额外维护一个队列，每次选择只需要从每个串的串首元素中进行筛选，选中的元素移入队列，最后将队列中的元素依次插入块状链表（每次插到块状链表末尾）即可。
{{ select(12) }}
-  $\sqrt{n}$
-  $n$
-  $n \sqrt{n}$
-  $n^2$

### （五）上机实践
13. `memset` 函数包含在以下（$\qquad$）头文件中。
{{ select(13) }}
-  `algorithm`
-  `cstring`
-  `functional`
-  `iomanip`

14. 已知函数 $f$ 的代码如下，则 $f(25)=$（$\qquad$）。
    ```cpp
    int f(int x) {return (x == 1) ? 1 : x * f(x / 2);}
    ```
{{ select(14) }}
-  $5400$
-  $5850$
-  $6825$
-  $9100$

15. 下面是一段错误的代码，在某些情况下会出现运行超时的问题。下列输入中会使程序运行超时的是（$\qquad$）。
    ```cpp
    #include <iostream>
    using namespace std;
    int main()
    {
        int x; // 1 <= x <= 7
        cin >> x;
        int l = 1, r = 7, m;
        while (1)
        {
            m = (l + r) >> 1;
            if (m < x) l = m;
            else if (m > x) r = m;
            else break;
        }
        cout << "Sorry Sleeping Frog, you performed an unsuccessful hacking attempt.";
        return 0;
    }
    ```
{{ select(15) }}
-  $1$
-  $3$
-  $5$
-  $7$

## 二、阅读程序（共 18 小题，除标注外，判断题 1 分，选择题 3 分，满分 40 分）
### （六）蜘蛛算经
```cpp
#include <iostream>
using namespace std;
int main()
{
    char c;
    int x = 0;
    while (cin >> c)
    {
        x <<= 3;              // Line 9
        int y = c - '0';
        x += y;
    }
    cout << x;
    return 0;
}                             // Line 15
```
> **输入格式：**
>
> 不超过 $10$ 个数字字符。

16. 将第 $9$ 行改为 `x *= 8`，对于任何输入，结果不变，程序可以正常运行。（$\qquad$）
{{ select(16) }}
-  对
-  错

17. 输入不同，输出就一定不同。（$\qquad$）
{{ select(17) }}
-  对
-  错

18. 对于某些输入，程序可能会出现整数溢出的问题。（$\qquad$）
{{ select(18) }}
-  对
-  错

19. 下列判断正确的是（$\qquad$）。
{{ select(19) }}
-  输入 `000`，输出 `3`
-  输入 `778`，输出 `1000`
-  输入 `123`，输出 `321`
-  输入 `111`，输出 `73`

20. 输入 `777`，输出（$\qquad$）。
{{ select(20) }}
-  `255`
-  `256`
-  `511`
-  `512`

21. **（4 分）** 输入 $10$ 个 `9`，输出最接近（$\qquad$）。
{{ select(21) }}
-  $11$ 亿
-  $12$ 亿
-  $13$ 亿
-  $14$ 亿

### （七）左手螺旋
```cpp
#include <iostream>
using namespace std;
int n, m, x, y;
char way;
bool a[1012][1012];
void report(int ans)
{
    cout << ans;
    exit(0);
}
int dy(char w)
{
    switch (w)
    {
        case 'R': return 1;
        case 'L': return -1;
        default: return 0;
    }
}
int dx(char w)
{
    switch (w)
    {
        case 'U': return -1;
        case 'D': return 1;
        default: return 0;
    }
}
char turn_left(char origin)
{
    switch (origin)
    {
        case 'L': return 'D';
        case 'D': return 'R';
        case 'R': return 'U';
        case 'U': return 'L';
    }
}
int main()
{
    cin >> n >> m;
    cin >> x >> y >> way;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    if (!a[x][y]) report(0);
    int ans = 0;
    while (ans <= 10 * n * m)                      // Line 48
    {
        ans++;
        if (a[x + dx(way)][y + dy(way)] == 1)      // Line 51
        {
            x += dx(way);
            y += dy(way);
            continue;
        }
        way = turn_left(way);
        if (a[x + dx(way)][y + dy(way)] == 1)      // Line 58
        {
             x += dx(way);
             y += dy(way);
             continue;
        }
        report(ans);
    }
    report(-1);                                    // Line 66
    return 0;
}                                                  // Line 68
```
> **输入格式：**
>
> 第一行两个正整数，分别为 $n,m\ (1 \le n,m \le 1000)$。
>
> 第二行两个正整数，分别为 $x,y\ (1 \le x \le n,1 \le y \le m)$。
> 
> 第三行一个字符，保证是 `L`，`R`，`U`，`D` 之一。
> 
> 下面一个 $n$ 行 $m$ 列的 01 矩阵。

22. 执行至第 $66$ 行时，$ans=10nm$。（$\qquad$）
{{ select(22) }}
-  对
-  错

23. 将第 $51$ 行和第 $58$ 行的两个 `1` 改为 `0`，则程序对于某些输入将出现数组越界的问题。（$\qquad$）
{{ select(23) }}
-  对
-  错

24. 若输入的 01 矩阵全为 `0`，则输出结果一定是 `0`。（$\qquad$）
{{ select(24) }}
-  对
-  错

25. 输入以下数据：
    ```plain
    5 4
    4 1
    D
    1 0 0 1
    1 0 0 0
    1 0 1 1
    1 1 0 1
    1 1 0 1
    ```
     则输出为（$\qquad$）。
{{ select(25) }}
-  `-1`
-  `1`
-  `4`
-  `5`

26. 输入 $n=m=1000,x=y=1$，01 矩阵全为 `1`，已知输出为 `1`，则第三行的字符是（$\qquad$）。
{{ select(26) }}
-  `U`
-  `D`
-  `L`
-  `R`

27. **（4 分）** 第 $48$ 行的 `while` 循环最多会被执行约（$\qquad$）次。
{{ select(27) }}
-  $10^3$
-  $10^4$
-  $10^6$
-  $10^7$

### （八）幸福之约
```cpp
#include <iostream>
using namespace std;
int pr[26];
bool prime(int x)
{
    if (x == 1) return false;                    // Line 6
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true; 
}
void set_pr(int v)
{
    int cnt = 0;
    for (int i = 2; i <= v; i++)
        if (prime(i)) cnt++, pr[cnt] = i;
}
int mv = 1, range;
void dfs(int div, int cur, int dep, int num)
{
    if (div > mv) mv = div;
    long long nc = cur;                          // Line 21
    for (int i = 1; i <= num; i++)
    {
        nc *= pr[dep];
        if (nc > range) return;
        dfs(div * (i + 1), nc, dep + 1, i);
    }
}
int main()
{
    set_pr(100);
    cin >> range;
    dfs(1, 1, 1, 30);
    cout << mv;
    return 0;
}                                                // Line 36
```
> **输入格式：**
>
> 一个不超过 $10^9$ 的正整数。

28. 删去第 $6$ 行后，程序对于所有输入仍能正常运行，结果不变。（$\qquad$）
{{ select(28) }}
-  对
-  错

29. 输入 `1`，输出 `1`。（$\qquad$）
{{ select(29) }}
-  对
-  错

30. 将第 $21$ 行的 `long long` 改为 `int`，则程序对某些输入将出现运行超时、空间超限等问题。（$\qquad$）
{{ select(30) }}
-  对
-  错

31. 程序运行至第 $21$ 行时，在 $1,2,3,\ldots,10$ 中，可能成为 `cur` 的值有（$\qquad$）个。
{{ select(31) }}
-  $4$
-  $5$
-  $6$
-  $7$

32. 程序运行过程中，`dep` 的最大可能值是（$\qquad$）。
{{ select(32) }}
-  $5$
-  $10$
-  $15$
-  $20$

33. **（5 分）** 输入 `1000000000`（$10^9$），输出（$\qquad$）。
{{ select(33) }}
-  `30`
-  `120`
-  `1344`
-  `32768`

## 三、补全程序（共 10 小题，每小题 3 分，满分 30 分）
### （九）方格计数

> **请在程序能运行的前提下尽量优化空间常数。**
>
> 求 $n$ 行 $m$ 列的表格中共有多少个格子。
> 
> $1 \le n,m \le 10^{1000}$。

```cpp
#include <iostream>
#include <string>
using namespace std;
const int X = /* (34)________ */;
const int Y = /* (35)________ */;
const int Z = /* (36)________ */;
int a[X], b[X], c[Y];
string mul(string x, string y)
{
    for (int i = 0, j = x.size() - 1; j >= 0; i++, j--)
        a[i] = x[j] - '0';
    for (int i = 0, j = y.size() - 1; j >= 0; i++, j--)
        b[i] = y[j] - '0';
    for (int i = 0; i <= x.size(); i++)
        for (int j = 0; j <= y.size(); j++)
            c[/* (37)________ */] += (a[i] * b[j]);
    for (int i = 0; i <= Y - 2; i++)
        if (c[i] >= Z) c[/* (38)________ */] += c[i] / Z, c[i] %= Z;
    int h = Y - 1;
    while (c[h] == 0 && h > 0) h--;
    string ans = "";
    for (int i = h; i >= 0; i--)
        ans += (char) (c[i] + '0');
    return ans;
}
int main()
{
    string n, m;
    cin >> n >> m;
    cout << mul(n, m);
    return 0;
}
```
34. 
{{ select(34) }}
-  `1000`
-  `1 << 10`
-  `2000`
-  `1 << 11`
35. 
{{ select(35) }}
-  `1000`
-  `1 << 10`
-  `2000`
-  `1 << 11`
36. 
{{ select(36) }}
-  `7`
-  `8`
-  `9`
-  `10`
37. 
{{ select(37) }}
-  `i + j`
-  `i - j`
-  `i * j`
-  `i / j`
38. 
{{ select(38) }}
-  `i - 1`
-  `i`
-  `i + 1`
-  `i + 2`

### （十）晚餐时间

> 在一座长度为 $T$ 的独木桥上有 $n$ 只小猪。
> 
> 现以独木桥左端为原点，向右为正方向建立数轴。
>
> 已知 $n$ 只小猪的位置分别为 $a_1,a_2,\ldots,a_n$。
>
> 这天晚上，Sleeping Frog 给他们投食了，它们要下桥吃饭。
> 
> 它们每秒同时按以下规则运动：
>
> - 数一数它左边和右边各有多少只猪。
> - 向猪更少的那个方向移动。
> - 如果两边猪的数量相等，它不移动。
> - 处于桥两端的猪跳下独木桥。
> 
> 当然，如果桥上只剩下一只猪时，它就再也不下来了。
>
> 求这些猪什么时候全部停止移动（跳下了桥也算停止移动）。
>
> $1 \le n \le 10^7$，$2 \le T \le 10^9$，$n < T$，$0 < a_1 < a_2 < \ldots < a_n < T$。

```cpp
#include <iostream>
using namespace std;
const int N = 1e7 + 12;
int a[N], dis[N];
int l, r, L, R, T, n;
int main()
{
	cin >> n >> T;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 1; i++)
		dis[i] = /* (39)________ */;
	l = 1, r = n, L = a[1], R = T - a[n];
	long long ans = 0;
	while (1)
	{
		int cnt = /* (40)________ */;
		if (cnt <= /* (41)________ */) break;
		int move = min(L, R);
		int mid = /* (42)________ */;
		if (cnt & 1)
		{
			dis[mid - 1] += move;
			dis[mid] += move;
		}
		else dis[mid] += /* (43)________ */;
		L -= move, R -= move, ans += move;
		if (L == 0) L = dis[l], l++;
		if (R == 0) R = dis[r - 1], r--;
	}
	cout << ans;
	return 0;
}
```
39. 
{{ select(39) }}
-  `a[i + 1] + a[i]`
-  `a[i] + a[i + 1]`
-  `a[i + 1] - a[i]`
-  `a[i] - a[i + 1]`

40. 
{{ select(40) }}
-  `l - r`
-  `r - l`
-  `l - r + 1`
-  `r - l + 1`
41. 
{{ select(41) }}
-  `0`
-  `1`
-  `2`
-  `3`
42. 
{{ select(42) }}
-  `(l + r) >> 1`
-  `(l + r) << 1`
-  `(l + r) + 1`
-  `(l + r) - 1`
43. 
{{ select(43) }}
-  `move >> 1`
-  `move << 1`
-  `move + 1`
-  `move - 1`
