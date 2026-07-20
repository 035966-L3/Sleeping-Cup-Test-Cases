## 注意

**本题版权归 Super League of Chinese College Students Algorithm Design 2022 (1) 的出题组所有。**

**题目来源：<https://qoj.ac/problem/4377>**

**本题需要文件读写（`knapsack.in` / `knapsack.out`）。**

## 题目描述

现有 $n$ 个商品，第 $i$ 个商品的价格为 $w_i$ 元，标签值为 $l_i$。

现需要用不超过 $m$ 元买下一些商品，问买下的商品的标签值的异或和最大为多少？

## 输入格式

第一行两个正整数 $n, m\ (1 \le n, m \le 100)$。

下面 $n$ 行，每行两个正整数 $w_i, l_i\ (1 \le w_i \le m, 1 \le l_i \le 1023)$。

## 输出格式

一行一个正整数表示答案。

## 样例

```input1
3 8
7 2
4 3
2 5
```

```output1
6
```

## 样例解释

最优方案是买下后两个商品。
