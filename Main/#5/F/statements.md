## 注意

本题版权归 AtCoder Inc. 所有。**

**题目来源：<https://atcoder.jp/contests/practice2/tasks/practice2_l>**

**本题需要使用文件读写（`inversion.in` / `inversion.out`）。**

**由于本题不涉及负数，你可以全程使用 `unsigned int` 计算以优化代码常数。**

**本题中 01 串的下标从 $\bm{0}$ 开始计数。**

**本题的 IO 量很大，因此请注意 IO 效率。**

**你可以使用以下代码（使用时需要包含 `<cstdio>` 或 `<bits/stdc++.h>` 头文件），并用 `read()` 读入一个非负整数，用 `writeline(x)` 输出一行一个非负整数 $\bm x$：**

```cpp
inline unsigned read()
{
	unsigned x = 0;
	char c = getchar_unlocked();
	while (c < '0') c = getchar_unlocked();
	while (c >= '0') x = x * 10 + c - '0', c = getchar_unlocked();
	return x;
}
inline void write(unsigned x)
{
	if (!x) return;
	write(x / 10);
	putchar_unlocked(x % 10 + '0');
}
inline void writeline(unsigned x)
{
	if (x) write(x);
	else putchar_unlocked('0');
	putchar_unlocked('\n');
}
```

**以下是本题的一些定义：**

- **「区间 $\bm{A_l \sim A_r}$ 的内部逆序对」被定义为满足以下三个条件的正整数对 $\bm{(L,R)}$：**
  - $\bm{A_L=\tt 1}$。
  - $\bm{A_R=\tt 0}$。
  - $\bm{l \le L < R \le r}$。
- **「反转区间 $\bm{A_l \sim A_r}$」被定义为以下操作：**
  - **对于区间 $\bm{A_l \sim A_r}$ 中的每一位 $\bm{A_i\ (l \le i \le r)}$：**
    - **如果 $\bm{A_i=\tt 1}$，那么执行操作 $\bm{A_i \gets \tt 0}$，即把它变成 $\tt 0$。**
    - **如果 $\bm{A_i=\tt 0}$，那么执行操作 $\bm{A_i \gets \tt 1}$，即把它变成 $\tt 1$。**

## 题目背景

[2lf](https://www.luogu.com.cn/user/824363) 认为他应该在靠后的位置出一些重口味的试题，比如……数据结构。

## 题目描述

现有一个长度为 $n$ 且初始全为 $\tt 0$ 的 01 串 $\{A_n\}$。

你需要执行以下两种指令各 $q$ 个，共计 $2q$ 个：

- 对于第 $1,3,5,\ldots,2q-1$ 个指令，给定两个整数 $0 \le l \le r \le n-1$，反转区间 $A_l \sim A_r$。
- 对于第 $2,4,6,\ldots,2q$ 个指令，给定两个整数 $0 \le l \le r \le n-1$，求出区间 $A_l \sim A_r$ 的内部逆序对个数。

## 输入格式

第一行两个正整数 $n,q$。

下面 $2q$ 行，每行两个非负整数 $l,r$。

## 输出格式

$q$ 行，每行一个非负整数，分别表示第 $2,4,6,\ldots,2q$ 个指令的答案。

## 下发文件

**我们下发了 `gen_samples.cpp` 作为 Generator，但没有下发样例。**

请在编译 `gen_samples.cpp` 为可执行文件 `gen_samples` 后使用以下命令生成样例：

- `gen_samples inversion.in inversion.ans`（Windows）。
- `./gen_samples inversion.in inversion.ans`（Linux）。

## 数据范围

- 对于上述 Generator 生成的样例数据，$n=q=2^8$。
- 对于实际测试数据，$n=2^{16}$，$q=2^{20}$。
- 保证实际测试数据的生成策略与上述 Generator 相同。
- 不保证实际测试数据与上述 Generator 使用了相同的随机数生成器。
- 保证 $0 \le l \le r \le n-1$。
