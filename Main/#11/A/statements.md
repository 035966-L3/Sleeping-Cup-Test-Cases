## 注意

**本题需要文件读写（`rating.in` / `rating.out`）。**

## 题目背景

这天早上，我们的吉祥物 Sleeping Kangaroo 正在重写 Sleeping Cup 的 Rating 计算程序……

## 题目描述

计算：

$$ R=\max\left\{\left\lfloor\sum ^n _{i=1} 2^{-i}Z_i\right\rfloor,1\right\} $$

## 输入格式

第一行一个正整数 $n\ (1 \le n \le 10^5)$。

第二行 $n$ 个正整数 $Z_1, Z_2, \ldots, Z_n\ (1 \le Z_i \le 10^9)$。

## 输出格式

一行一个正整数表示答案。

## 样例

```input1
1
1
```

```output1
1
```

```input2
1
2
```

```output2
1
```

```input3
1
3
```

```output3
1
```

```input4
1
4
```

```output4
2
```

```input5
2
3 1
```

```output5
1
```

```input6
2
3 2
```

```output6
2
```

## 样例 1 解释

$$ \sum ^n _{i=1} 2^{-i}Z_i = 0.5 $$

## 样例 2 解释

$$ \sum ^n _{i=1} 2^{-i}Z_i = 1 $$

## 样例 3 解释

$$ \sum ^n _{i=1} 2^{-i}Z_i = 1.5 $$

## 样例 4 解释

$$ \sum ^n _{i=1} 2^{-i}Z_i = 2 $$

## 样例 5 解释

$$ \sum ^n _{i=1} 2^{-i}Z_i = 1.75 $$

## 样例 6 解释

$$ \sum ^n _{i=1} 2^{-i}Z_i = 2 $$
