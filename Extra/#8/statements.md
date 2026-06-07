## 注意

**本题由 [aiyou](https://github.com/aiyou945) 搬运，版权归 AtCoder Inc. 所有。**

**题目来源：<https://atcoder.jp/contests/abc300/tasks/abc300_d>**

**本题需要使用文件读写（`triples.in` / `triples.out`）。**

## 题目描述

求满足以下条件的三元组 $(a, b, c)$ 的个数：

- $a, b, c$ 均为质数
- $a < b < c$
- $a^2 b c^2 \le n$

## 输入格式

一行一个正整数 $n\ (1 \le n \le 10^{12})$。

## 输出格式

一行一个非负整数表示答案。

## 样例

```input1
1
```

```output1
0
```

```input2
10
```

```output2
0
```

```input3
100
```

```output3
0
```

```input4
1000
```

```output4
3
```

## 样例 4 解释

符合要求的三元组有：

- $(2, 3, 5)$
- $(2, 3, 7)$
- $(2, 5, 7)$
