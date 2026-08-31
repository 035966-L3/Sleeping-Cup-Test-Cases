## 一、基础知识（共 15 小题，每小题 2 分，满分 30 分）
### （一）环境配置
1. 下列关于图灵机的说法一定不正确的是（$\qquad$）。
{{ select(1) }}
-  有无穷多个
-  包含无穷多个状态
-  接受无穷多种输入
-  能运行无穷多步而不停机

2. 摩尔定律对（$\qquad$）的性能迭代速度做出了预测。
{{ select(2) }}
-  CPU
-  GPU
-  RAM
-  ROM

3. 在 NOI Linux 2.0 上安装 GNU G++ 9.3.0 编译器的方式是（$\qquad$）。
{{ select(3) }}
-  系统预装
-  通过 apt 包管理器获取
-  通过 Git 拉取 Github 仓库得到二进制文件
-  在 GNU 官网获取源代码自行构建

### （二）系统操作
4. 在 `/home` 目录下执行下列命令，执行结果与其他三个差异最大的是（$\qquad$）。
{{ select(4) }}
-  `cd .`
-  `cd ..`
-  `cd /`
-  `cd //`

5. 在某个时间限制为 $1$ 秒的题目下，某测试点的自测结果如下，则（$\qquad$）。
   ```plain
   real    0m1.931s
   user    0m0.945s
   sys     0m0.985s
   ```
{{ select(5) }}
-  超过时间限制，以此申诉可能会被接受
-  超过时间限制，以此申诉一定不会被接受
-  没有超过时间限制，以此申诉可能会被接受
-  没有超过时间限制，以此申诉一定不会被接受

6. 下列指令中会让待编译的 C++ 程序无法通过编译的是（$\qquad$）。
{{ select(6) }}
-  `echo "int main(){}" > A.cpp && g++ A.cpp -O2 -lm -fsanitize=undefined`
-  `echo "int main(){}" > B.cpp && g++ B.cpp -static -fsanitize=undefined`
-  `echo "int main(){}" > C.cpp && g++ C.cpp -O2 -lm -fsanitize=address`
-  `echo "int main(){}" > D.cpp && g++ D.cpp -static -fsanitize=address`

### （三）程序编写
7. 下列头文件中被 `bits/stdc++.h` 包含的是（$\qquad$）。
{{ select(7) }}
-  `glad`
-  `locale`
-  `opencv2`
-  `sys`

8. 下面两个数组占用的空间分别为（$\qquad$）。

   ```cpp
   struct E { void greet() { puts("Hello!"); } } e[1024];
   union U { int x; char y; } u[1024];
   ```

{{ select(8) }}
-  0，4 KiB
-  0，5 KiB
-  1 KiB，4 KiB
-  1 KiB，5 KiB

9. 在 `-O0` 开关下，以下代码的时间复杂度是（$\qquad$）。

   ```cpp
   int f(int n)
   {
   	if (n <= 1) return n;
   	int s = 0;
   	for (int i = 1; i <= n - 1; i++)
   		s += f(n - i);
   	return s;
   }
   ```

{{ select(9) }}
-  $O(n^2)$
-  $O(2^n)$
-  $O(n!)$
-  $O(n^n)$

### （四）逻辑推理
10. 存储 $16$ 位二进制数至少需要（$\qquad$）个三进制位。
{{ select(10) }}
-  $11$
-  $12$
-  $13$
-  $14$

11. 同时接受 `ABCDEF`、`ABCFED`、`ACEFDB` 三个序列作为 DFS 序的有根树有（$\qquad$）棵。
{{ select(11) }}
-  $1$
-  $2$
-  $4$
-  $8$

12. Sleeping Lion 带着 $10$ 匹速度互不相同的马穿越到了战国时期，重新组织了一次「田忌赛马」，并安排对局让田忌以 $3 : 2$ 险胜齐威王，则开赛前可能的马匹分配方式有（$\qquad$）种。
{{ select(12) }}
-  $194$
-  $195$
-  $196$
-  $197$

### （五）按位求解
> 给定序列 $[0, 1, 9, 10, 16, 19, 20, 27]$，**请完成下面三个问题**：

13. 在相邻两项间填入 $\land, \lor, \oplus$ 中的一个，所组成的算式可能出现的最大运算结果是（$\qquad$）。
{{ select(13) }}
-  $28$
-  $29$
-  $30$
-  $31$

14. 从中选出两个数，能够得到的最大异或和为（$\qquad$）。
{{ select(14) }}
-  $28$
-  $29$
-  $30$
-  $31$

15. 下面四个上述序列的子序列中，对应集合不存在所含元素异或和为 $0$ 的非空子集的是（$\qquad$）。
{{ select(15) }}
-  $[0, 9, 16, 19, 20]$
-  $[0, 9, 16, 19, 27]$
-  $[1, 9, 16, 20, 27]$
-  $[1, 9, 19, 20, 27]$

## 二、阅读程序（共 18 小题，除标注外，判断题 1 分，选择题 3 分，满分 40 分）
### （六）单词缩写
```cpp
#include <cstdio>
#include <cstring>
using namespace std;
char s[50];
int main()
{
	int P = scanf("%s", s + 1);
	int Q = printf("%c%u%c\n", s[1], strlen(s + 1) - 2, s[strlen(s + 1)]);
	return 0;
}                                                                               // Line 10
```
> **输入格式：**
>
> 不超过 $40$ 个（但不少于 $1$ 个）大小写拉丁字母字符。

16. $P = 1$。（$\qquad$）
{{ select(16) }}
-  对
-  错

17. $Q = 3$。（$\qquad$）
{{ select(17) }}
-  对
-  错

18. 输入 `a`，输出 `a-1a`。（$\qquad$）
{{ select(18) }}
-  对
-  错

19. 在 NOI Linux 2.0 下，从控制台读入时，（$\qquad$）可以代替回车让程序结束读入。
{{ select(19) }}
-  Ctrl + A
-  Ctrl + B
-  Ctrl + C
-  Ctrl + D

20. 忽略输入格式要求，输入 `Sleeping Lion`，输出（$\qquad$）。
{{ select(20) }}
-  `S6g`
-  `S8g`
-  `S11n`
-  `S13n`

21. **（4 分）** 忽略输入格式要求，下列输入中不会使得程序行为未定义的最长输入是（$\qquad$）。
{{ select(21) }}
-  输入 $48$ 个 `a`
-  输入 $49$ 个 `a`
-  输入 $50$ 个 `a`
-  输入 $51$ 个 `a`

### （七）休息时间
```cpp
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
pair <int, int> c[100012];
bool cmp(pair <int, int> first, pair <int, int> second)
{
	return first.first < second.first;
}
int main()
{
	int n, k, x = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> c[i].first >> c[i].second;
	sort(c + 1, c + n + 1, cmp);                                // Line 16
	for (int i = 1; i <= n; i++)
	{
		if (c[i].first - x >= 2)
			cout << x + 1 << ' ' << c[i].first - 1 << endl;
		x = max(x, c[i].second);
	}
	if (x < k) cout << x + 1 << ' ' << k;
	return 0;
}                                                               // Line 25
```
> **输入格式：**
>
> 第一行两个正整数，分别为 $n, k\ (0 \le n \le 10^5, 1 \le k \le 10^9)$。
>
> 下面 $n$ 行，第 $i$ 行两个正整数 $l_i, r_i\ (1 \le l_i \le r_i \le k)$。

22. 该程序的时间复杂度为 $O(n)$。（$\qquad$）
{{ select(22) }}
-  对
-  错

23. 输出数据中每行的第一个整数总是不大于第二个整数。（$\qquad$）
{{ select(23) }}
-  对
-  错

24. 将第 $16$ 行的 `c + 1` 改为 `c`，程序对所有输入的运行结果不变。（$\qquad$）
{{ select(24) }}
-  对
-  错

25. 输入以下数据：
    ```plain
    5 25
    2 8
    3 7
    11 15
    16 20
    <1> 23
    ```
    输出结果为：
    ```plain
    1 1
    9 10
    21 22
    <2> 25
    ```
    填写 `<1>` 处和 `<2>` 处缺失的内容：（$\qquad$）
{{ select(25) }}
-  $22$，$23$
-  $22$，$24$
-  $23$，$23$
-  $23$，$24$

26. 输入以下数据：
    ```plain
    5 20
    1 3
    6 10
    11 13
    16 20
    <3> <4>
    ```
    输出结果为空，则填写 `<3>` 处和 `<4>` 处缺失的内容的方案数为：（$\qquad$）
{{ select(26) }}
-  $15$
-  $24$
-  $35$
-  $48$


27. **（4 分）** 输出数据至多有（$\qquad$）行。
{{ select(27) }}
-  $n$
-  $n + 1$
-  $2n$
-  $2n + 1$

### （八）重心分解
```cpp
#include <algorithm>                                                                        // Line 1
#include <iostream>
#include <vector>
using namespace std;
int size1[100012], size2[100012], layer[100012], above[100012];
vector <int> e[22][100012], d[100012];
bool label[22][100012];
void dfs0(int x, int up, int round)
{
	size1[x] = 0;                                                                           // Line 10
	size2[x] = 0;                                                                           // Line 11
	label[round + 1][x] = true;
	for (auto y: e[round][x])
	{
		if (y == up) continue;                                                              // Line 15
		dfs0(y, x, round);
	}
}
int dfs1(int x, int up, int round)
{
	size1[x] = 1;
	for (auto y: e[round][x])
	{
		if (y == up) continue;
		size1[x] += dfs1(y, x, round);
	}
	return size1[x];
}
void dfs2(int n, int x, int up, int round)
{
	size2[x] = n - size1[x];
	for (auto y: e[round][x])
	{
		if (y == up) continue;
		size2[x] = max(size2[x], size1[y]);
		dfs2(n, y, x, round);
	}
}
void dfs3(int x, int up, int top, int round)
{
	above[x] = top;
	if (x != top && up != top)
	{
		e[round + 1][x].push_back(up);
		e[round + 1][up].push_back(x);
	}
	for (auto y: e[round][x])
	{
		if (y == up) continue;
		dfs3(y, x, top, round);
	}
}
int center(int n, int start, int round)                                                     // Line 53
{
	int total = dfs1(start, 0, round);
	dfs2(total, start, 0, round);
	for (int i = 1; i <= n; i++)
		if (size1[i] && 2 * size2[i] <= total)
		{
			dfs0(start, 0, round);                                                          // Line 60
			return i;
		}
	return -1;
}
void build(int n)
{
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= n; j++)
			if (!layer[j] && !label[i][j])
			{
				int root = center(n, j, i - 1);
				layer[root] = i;
				if (i >= 2)
				{
					d[root].push_back(above[root]);
					d[above[root]].push_back(root);
				}
				dfs3(root, 0, root, i - 1);
			}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		e[0][x].push_back(y);
		e[0][y].push_back(x);
	}
	build(n);
	for (int i = 1; i <= n; i++)
	{
		sort(d[i].begin(), d[i].end());
		for (auto y: d[i])
			if (y > i) cout << i << ' ' << y << endl;
	}
	return 0;
}                                                                                           // Line 100
```
> **输入格式：**
>
> 第一行一个正整数 $n\ (1 \le n \le 10^5)$，表示无向图 $T$ 的结点个数。
>
> 约定 $T$ 中 $n$ 个结点的标号分别为 $1, 2, \ldots, n$。
>
> 下面 $n - 1$ 行，第 $i$ 行两个正整数 $u_i, v_i\ (1 \le u_i < v_i \le n)$，表示 $T$ 中的一条无向边 $u_i \leftrightarrow v_i$。
>
> $T$ 中有且仅有输入数据中描述的无向边。
> 
> 保证 $T$ 是一棵无根树。
>
> 约定无向图 $S$ 中 $n$ 个结点的标号分别为 $1, 2, \ldots, n$。
> 
> 输出数据中第 $i$ 行的两个正整数 $x_i, y_i\ (1 \le x_i < y_i \le n)$ 表示 $S$ 中的一条无向边 $x_i \leftrightarrow y_i$。
>
> $S$ 中有且仅有输出数据中描述的无向边。

28. 第 $53$ 行的 `center` 函数不可能返回 $-1$。（$\qquad$）
{{ select(28) }}
-  对
-  错

29. 删去第 $15$ 行，则程序可能会出现运行超时、运行错误等问题。（$\qquad$）
{{ select(29) }}
-  对
-  错

30. 删去第 $10$ 行和第 $11$ 行，在第 $1$ 行后加入 `#include <cstring>`，在第 $60$ 行后加入 `memset(size1, 0, sizeof size1);` 和 `memset(size2, 0, sizeof size2);`，则新程序在最坏情况下的时间复杂度比原程序更劣。（$\qquad$）
{{ select(30) }}
-  对
-  错

31. 输入以下数据：
    ```plain
    8
    1 2
    3 4
    5 6
    7 8
    2 4
    4 6
    6 8
    ```
    则输出数据中所有正整数的和为（$\qquad$）。
{{ select(31) }}
-  $61$
-  $62$
-  $63$
-  $64$

32. 程序运行过程中，`layer` 数组中元素的最大可能值是（$\qquad$）。
{{ select(32) }}
-  $15$
-  $16$
-  $17$
-  $18$

33. **（5 分）** 以下输入数据中均有 $v_i = i + 1$，其中会导致 $S$ 与 $T$ 不同构的是（$\qquad$）。
{{ select(33) }}
-  $n = 1$
-  $n = 10^5$，$u_i = 1$
-  $n = 10^5$，$u_i = i$
-  $n = 2^{16} - 1$，$u_1 = u_2 = 1$，$u_i = u_{i - 2} + 1\ (3 \le i \le n - 1)$

## 三、补全程序（共 10 小题，每小题 3 分，满分 30 分）
### （九）前缀最大

> 现有一个 $1, 2, \ldots, n$ 的排列 $b$，设 $a_i$ 为 $b$ 中前 $i$ 项的最大值，给定序列 $a$，试构造一个合法的排列 $b$，如果无解则输出 $-1$。
> 
> $1 \le n \le 10^7$，$1 \le a_i \le n$。

```cpp
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int a[10000012], b[10000012];
queue <int> c;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		if (a[i] /* (34) _____ */ max(a[i - 1], i))
		{
			puts("-1");
			return 0;
		}
	for (int i = 1; i <= n; i++)
		if (a[i] /* (35) _____ */ a[i - 1])
		{
			b[i] = a[i];
			for (int j = /* (36) _____ */; j <= /* (37) _____ */; j++)
				c.push(j);
		}
	for (int i = 1; i <= n; i++)
	{
		if (b[i]) continue;
		int d = c.front();
		c.pop();
		b[i] = d;
	}
	for (int i = 1; i <= /* (38) _____ */; i++)
		printf("%d ", b[i]);
	printf("%d\n", b[n]);
	return 0;
}
```
34. 
{{ select(34) }}
-  `>`
-  `>=`
-  `<`
-  `<=`
35. 
{{ select(35) }}
-  `>`
-  `>=`
-  `<`
-  `<=`
36. 
{{ select(36) }}
-  `1`
-  `a[i - 1] - 1`
-  `a[i - 1]`
-  `a[i - 1] + 1`
37. 
{{ select(37) }}
-  `1`
-  `a[i] - 1`
-  `a[i]`
-  `a[i] + 1`
38. 
{{ select(38) }}
-  `1`
-  `n - 1`
-  `n`
-  `n + 1`

### （十）安全样例

> 定义一个「安全的样例」为满足以下条件的数字：
>
> - 是不大于 $n$ 的正整数。
> - 十进制表示中不包含子串 $S$。
>
> 求「安全的样例」的数量对 $10^9 + 7$ 取模后的结果。
>
> $1 \le n \le 10^{1000}$，$1 \le |S| \le 1000$，$S$ 中只含数字字符。

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#define B39 /* (39) _____ */
#define B40 /* (40) _____ */
#define B41 /* (41) _____ */
#define B42 /* (42) _____ */
#define B43 /* (43) _____ */
using namespace std;
const int P = 1e9 + 7;
int f[1012][1012][2], p[1012];
void accumulate(int& x, int y)
{
	x += y;
	if (x >= P) x -= P;
}
int main()
{
	string n, S;
	cin >> n >> S;
	reverse(n.begin(), n.end());
	int m = (int) S.size(), l = (int) n.size() - 1;
	S = ' ' + S;
	for (int i = 2; i <= m; i++)
	{
		int h = p[i - 1];
		while (h)
		{
			if (B39) break;
			B40;
		}
		if (B39) h++;
		p[i] = h;
	}
	for (int j = 1; j <= n[l] - '0'; j++)
		f[l][B41][j == n[l] - '0'] = 1;
	for (int i = l - 1; i >= 0; i--)
		for (int j = 1; j <= 9; j++)
			f[i][B41][0]++;
	for (int i = l - 1; i >= 0; i--)
		for (int j = 0; j <= B42; j++)
			for (int k = 0; k <= 9; k++)
			{
				int h = j;
				while (B43 && h) B40;
				if (!(B43)) h++;
				accumulate(f[i][h][0], f[i + 1][j][0]);
				if (k <= n[i] - '0') accumulate(f[i][h][k == n[i] - '0'], f[i + 1][j][1]);
			}
	int a = 0;
	for (int i = 0; i <= B42; i++)
	{
		accumulate(a, f[0][i][0]);
		accumulate(a, f[0][i][1]);
	}
	cout << a << endl;
	return 0;
}
```
39. 
{{ select(39) }}
-  `S[h] == S[i]`
-  `S[h] == S[i + 1]`
-  `S[h + 1] == S[i]`
-  `S[h + 1] == S[i + 1]`
40. 
{{ select(40) }}
-  `h = p[h]`
-  `h = p[h] + 1`
-  `h = p[h + 1]`
-  `h = p[h + 1] + 1`
41. 
{{ select(41) }}
-  `j == S[0] - '0'`
-  `j != S[0] - '0'`
-  `j == S[1] - '0'`
-  `j != S[1] - '0'`
42. 
{{ select(42) }}
-  `1`
-  `m - 1`
-  `m`
-  `m + 1`
43. 
{{ select(43) }}
-  `k == S[h] - '0'`
-  `k != S[h] - '0'`
-  `k == S[h + 1] - '0'`
-  `k != S[h + 1] - '0'`
