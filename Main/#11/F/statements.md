## 注意

**本题需要文件读写（`backward.in` / `backward.out`）。**

**本题的原始数据没有针对任何哈希算法（包括但不限于普通的字符串多项式哈希、使用默认哈希函数的 `std::unordered_set`、使用默认哈希函数的 `std::unordered_map` 等）进行特定构造，但接受基于哈希算法攻击的 hack 数据。如果你需要使用继续字符串哈希的解法，请尽量使用难以被攻击的哈希算法。以下是一个较为安全的哈希算法的示例，该示例需要包含 `<cassert>`（或 `<assert.h>`）、`<random>`、`<vector>`，`<string>` 四个头文件（或者 `<bits/stdc++.h>` 一个头文件）并使用不低于 C++14 的版本提交：**

```cpp
struct Barrett_Reduction
{
	unsigned int m;
	unsigned long long I;
	inline void init(unsigned int p)
	{
		assert(p >= 2);
		m = p;
		I = ((unsigned __int128) 1 << 64) / m;
	}
	inline unsigned int reduce(unsigned long long a)
	{
		unsigned long long q = ((unsigned __int128) a * I) >> 64;
		unsigned long long r = a - q * m;
		if (r >= m) r -= m;
		return r;
	}
};
struct Miller_Rabin
{
	int power(int a, int b, int p)
	{
		if (b == 1) return a;
		int x = power(a, b >> 1, p);
		x = 1ll * x * x % p;
		if (b & 1) x = 1ll * x * a % p;
		return x;
	}
	inline bool check(int n, int h, int a)
	{
		if (n % a == 0) return false;
		int now = power(a, h, n);
		if (now == 1) return true;
		while (h != n - 1)
		{
			if (now == n - 1) return true;
			now = 1ll * now * now % n;
			h <<= 1;
		}
		return false;
	}
	inline bool prime(int n)
	{
		int h = n - 1;
		while ((h & 1) == 0) h >>= 1;
		if (!check(n, h, 2)) return false;
		if (!check(n, h, 7)) return false;
		if (!check(n, h, 61)) return false;
		return true;
	}
};
struct Hash
{
	string s;
	unsigned long long b;
	Barrett_Reduction p[2];
	std::vector <unsigned long long> u[2];
	std::vector <unsigned long long> v[2];
	inline void pre_init()
	{
		Miller_Rabin m;
		std::random_device r;
		for (int i = -1; i <= 1; i++)
		{
			unsigned int q = 500000000 + i * 200000000 + r() % 100000000;
			while (!m.prime(q)) q++;
			if (i == -1) b = q;
			if (i >= 0) p[i].init(q);
		}
	}
	inline void init(std::string s)
	{
		assert(s != "");
		for (int i = 0; i <= 1; i++)
		{
			u[i].push_back(p[i].m - 1);
			for (int j = 1; j <= (int) s.size(); j++)
				u[i].push_back(p[i].reduce(u[i].back() * b));
			v[i].push_back(0);
			v[i].push_back(s[0]);
			for (int j = 2; j <= (int) s.size(); j++)
				v[i].push_back(p[i].reduce(v[i].back() * b + s[j - 1]));
		}
		this -> s = s;
	}
	inline std::vector <unsigned long long> query(int l, int r)
	{
		assert(l >= 1 && r <= (int) s.size() && l <= r);
		std::vector <unsigned long long> w;
		for (int i = 0; i <= 1; i++)
			w.push_back(p[i].reduce(v[i][r] + v[i][l - 1] * u[i][r - l + 1]));
		return w;
	}
	inline bool identical(int l1, int r1, int l2, int r2)
	{
		assert(l1 >= 1 && r1 <= (int) s.size() && l1 <= r1);
		assert(l2 >= 1 && r2 <= (int) s.size() && l2 <= r2);
		if (r1 - l1 != r2 - l2) return false;
		std::vector <unsigned long long> t1 = query(l1, r1);
		std::vector <unsigned long long> t2 = query(l2, r2);
		for (int i = 0; i <= 1; i++)
			if (t1[i] != t2[i]) return false;
		return true;
	}
};
```

## 题目描述

给定一个仅由小写字母组成的字符串 $S$，已知字符串 $T$ 满足：

- $T$ 是 $S$ 的子串。
- 将 $T$ 翻转得到 $T'$，则 $T'$ 是 $S$ 的子串。
- 存在一种从 $S$ 中选取这两个字符串的方法，使得两个子串不共享字符。

求 $T$ 的最大可能长度。

## 输入格式

一行一个小写字母组成的字符串 $S\ (1 \le |S| \le 10^5)$。

## 输出格式

一行一个非负整数表示答案。

## 样例

```input1
workspace
```

```output1
0
```

```input2
iteration
```

```output2
2
```

```input3
zzzzzzzzz
```

```output3
4
```

## 样例 1 解释

最长的 $T$ 是空串。

## 样例 2 解释

最长的 $T$ 是 $\texttt{it}$ 和 $\texttt{ti}$。

## 样例 3 解释

最长的 $T$ 是 $\texttt{zzzz}$。
