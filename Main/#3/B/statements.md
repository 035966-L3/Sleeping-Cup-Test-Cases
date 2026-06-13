## 注意

**请严格按照提交方式进行操作。**

**本题的空间限制为 8 MB。**

## 题目描述

求给定的 $n$ 个正整数（保证有奇数个）的中位数。

## 提交方式

请使用以下模板。你的程序将会读入一行两个正整数 $n,x$（保证 $n$ 为奇数），然后调用 $n$ 次 `get()` 函数以获得 $n$ 个正整数的值（保证不大于 $2^{32}-1$）。你需要在获得 $n$ 个正整数的值后输出它们的中位数。

```cpp
#include <bits/stdc++.h>
using namespace std;
unsigned int n, x;
inline unsigned int get()
{
	x ^= x << 7;
	x ^= x >> 23;
	x ^= x << 12;
	return x;
}
int main()
{
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	cin >> n >> x;
	unsigned int answer = 0;
	// Call the function 'get()' to get the integers.
	// You should call the function 'get()' exactly N times.
	// An integer will be given after each call.
	cout << answer << endl;
	return 0;
}
```

## 样例

```input1
1 3489531249
```

```output1
4213554576
```

```input2
3 3489531249
```

```output2
3736028483
```

```input3
5 3489531249
```

```output3
1591798959
```

```input4
7 3489531249
```

```output4
1591798959
```

```input5
9 3489531249
```

```output5
1591798959
```

## 样例解释

`get()` 函数返回的前 $9$ 项分别是：

```plain
4213554576
3736028483
1464923601
1591798959
1159830386
399619033
2061643431
1546026288
3242329518
```

## 数据范围

- 对于 $50\%$ 的数据，$1 \le n \le 10^5+1$。
- 对于 $100\%$ 的数据，$1 \le n \le 10^8+1$，$1 \le x \le 2^{32}-1$。
