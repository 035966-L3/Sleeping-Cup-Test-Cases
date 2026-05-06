## 注意

**本题需要文件读写（`compounds.in` / `compounds.out`）。**

**在本题中，两个关于序列 $\bm{\{a_1, a_2, \ldots, a_n\}}$ 的表达式 $\bm{f(a_1, a_2, \ldots, a_n)}$ 和 $\bm{g(a_1, a_2, \ldots, a_n)}$ 等价，当且仅当不存在序列 $\bm{\{b_1, b_2, \ldots, b_n\}}$ 使得 $\bm{f(b_1, b_2, \ldots, b_n) \ne g(b_1, b_2, \ldots, b_n)}$。**

**本题不考虑 C++ 语言中变量的取值范围，认为变量的值可以取任意实数。**

**你可以使用以下模板判定测试数据所属的子任务编号：**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("compounds.in", "r", stdin);
	freopen("compounds.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		string S;
		cin >> S;
		if (S.find("5") == string::npos)
		{
			// 子任务 1：保证基本参数不超过 4 个
			continue;
		}
		if (S.find("x") == string::npos)
		{
			// 子任务 2：保证所有运算都是 std::min
			continue;
		}
		if (S.find("(m") == string::npos)
		{
			// 子任务 3：保证每层运算的第一个参数只使用一个基本参数
			continue;
		}
		// 子任务 4：无特殊限制
	}
	return 0;
}
```

## 题目背景

> ```cpp
> [C++ / Algorithm Library / std::max]
> (Defined in header <algorithm>)
>
> (1)           template <class T>
>               const T& max (const T& a, const T& b);
> (2)           template <class T, class Compare>
>               const T& max (const T& a, const T& b, Compare comp);
> (3)  [C++11]  template <class T>
>               T max (std::initializer_list <T> ilist);
> (4)  [C++11]  template <class T, class Compare>
>               T max (std::initializer_list <T> ilist, Compare comp);
>
> Returns the greater of the given values.
> ```
>
>（资料来源：<https://cppreference.com/w/cpp/algorithm/max.html>）

Sleeping Iguana 还记得它 2020 年学习 C++ 语法时，调用 `std::max` 函数的情景：

```cpp
return max(max(a, b), max(c, d));
```

（根据程序设计竞赛的主流编码风格，程序开头一般会使用 `using namespace std;` 将 `std` 指定为默认的命名空间，因此此处省去了 `std::` 命名空间。）

当时，它询问老师能不能这样写，老师告诉它「当然可以」。

但现在是 2026 年，时代大变，于是它看到了……

```cpp
return max({a, b, c, d});
```

唉，转眼间我们的 Sleeping Iguana 就成为 2020 年的老古董了吗？

## 题目描述

生活在 2026 年的 Sleeping Iguana 翻看了自己 2020 年编写的代码，发现了一个包含大量 `std::min` 和 `std::max` 函数嵌套的复杂表达式，传入其中的所有参数均为两两之间相互独立的变量。

Sleeping Iguana 意识到，它现在可以借助 `std::min` 和 `std::max` 函数接受 `std::initializer_list` 作为参数的特性化简这一表达式，减少 `std::min` 和 `std::max` 函数的调用次数。

已知化简的唯一原则是「简化前后的表达式等价」，那么化简后 `std::min` 和 `std::max` 函数的调用次数之和最少是多少？

## 输入格式

**本题有多组测试数据。**

第一行输入一个正整数 $T$，表示测试数据的数量。

接下来，对于每组测试数据，输入一行一个字符串 $S$，表示待化简的表达式。

字符串 $S$ 的格式请参见「数据范围」部分。

## 输出格式

对于每组测试数据，输出一行一个正整数，表示简化后 `std::min` 和 `std::max` 函数的调用次数之和的最小值。

## 样例

```input1
4
max(min(a[1],a[2]),min(a[3],a[4]))
min(min(min(a[1],a[2]),min(a[3],a[4])),min(a[5],a[6]))
max(a[1],max(a[2],min(a[3],min(a[4],max(a[5],a[6])))))
min(max(max(min(a[1],a[2]),max(a[3],a[4])),a[5]),min(a[6],max(a[7],a[8])))
```

```output1
3
1
3
4
```

## 样例解释

本样例将作为子任务 4 的首个测试点进行评测。

前 3 组测试数据依次满足前 3 个子任务的特殊限制。

对于第 4 组测试数据，一种最优的化简结果为：

```cpp
min({max({min(a[1],a[2]),a[3],a[4],a[5]}),a[6],max(a[7],a[8])})
```

作为参考，在「数据范围」部分给出的程序中输入以下内容可以得到本样例：

```plain
4

1 4
2 1
1 0
1 0

2 6
4 0
2 0
1 0
1 0
1 0

3 6
1 1
1 1
1 0
1 0
1 1

4 8
5 0
4 1
2 1
1 0
1 1
1 0
1 1
```

## 数据范围

```cpp
#include <bits/stdc++.h>
using namespace std;
int read(int l, int r) // 读入一个整数，要求在 [l, r] 范围内
{
	int n;
	cin >> n;
	assert(n >= l && n <= r);
	return n;
}
int counter = 0;
char output[1400012]; // 存放生成的字符串：可以证明，单个字符串包含的字符个数不超过 1.4 * 10^6
char* pointer = output;
int subtask; // 子任务编号
void divide(int n) // 生成包含 n 个基本参数的二元运算表达式
{
	if (n == 1) // n = 1，生成单个基本参数 a[x]
	{
		counter++;
		pointer += sprintf(pointer, "a[%d]", counter);
		return;
	}
	int left = read(1, n - 1); // 递归确定本层运算第一个参数使用的基本参数个数
	if (subtask == 3) left = 1; // 子任务 3：保证每层运算的第一个参数只使用一个基本参数
	int type = read(0, 1); // 决定本层的运算，输入 0 表示 std::min，输入 1 表示 std::max
	if (subtask == 2) type = 0; // 子任务 2：保证所有运算都是 std::min
	if (!type) pointer += sprintf(pointer, "min(");
	if (type) pointer += sprintf(pointer, "max(");
	divide(left); // 递归生成第一个参数
	pointer += sprintf(pointer, ",");
	divide(n - left); // 递归生成第二个参数
	pointer += sprintf(pointer, ")");
}
int main()
{
	int T = read(1, 10); // 输入测试数据的数量，保证在 [1, 10] 范围内
	printf("%d\n", T);
	while (T--)
	{
		memset(output, 0, sizeof output);
		pointer = output;
		counter = 0;
		subtask = read(1, 4); // 输入该组测试数据对应的子任务编号，其中子任务 4 无特殊限制
		int n = read(2, 1e5); // 输入基本参数个数，保证在 [2, 10^5] 范围内
		if (subtask == 1) n = min(n, 4); // 子任务 1：保证基本参数不超过 4 个
		divide(n);
		printf("%s\n", output);
	}
	return 0;
}
```

对于所有子任务，输入数据可以由上面的程序在不发生运行时错误的情况下生成。

本题共有 4 个等分的子任务，各子任务的特殊限制详见上面的程序，其中子任务 4 依赖于其他所有子任务。
