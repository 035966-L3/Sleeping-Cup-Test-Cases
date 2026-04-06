## 注意

**本题的子任务依赖关系如下：**

| 子任务编号 | 依赖的子任务编号 |
| :-: | :-: |
| 子任务 1 | 无 |
| 子任务 2 | 子任务 1 |
| 子任务 3 | 子任务 2 |
| 子任务 4 | 子任务 3 |

**本题需要使用文件读写（`league.in` / `league.out`）。**

## 题目背景

上次，Sleeping Goose 的好朋友 Sleeping Dolphin 的球队输掉了比赛，于是它们提前 $45$ 年开始了 $2070$ 年白鹅星世界杯的备战，准备到时候大展身手。

为防止再次被踢爆，睡超联赛诞生了。

## 题目描述

已知联赛中有 $n$ 支球队，当联赛中的球队数大于 $15$ 支队伍时，比赛采用[单循环赛制](https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&rsv_idx=1&tn=baidu&wd=%E5%8D%95%E5%BE%AA%E7%8E%AF%E8%B5%9B%E5%88%B6&fenlei=256&oq=%25E5%258D%2595%25E5%25BE%25AA%25E7%258E%25AF%25E8%25B5%259B%25E5%2588%25B6%25E3%2580%2581&rsv_pq=e78d687900e7e6dc&rsv_t=87e8%2BG95OvwrsJqfP1Qxv6yDyA0MeN0skdRQ%2FBPHyXSJqq42izS7h0yVoXg&rqlang=cn&rsv_enter=1&rsv_dl=tb&rsv_btype=t&rsv_sug3=4&rsv_sug1=2&rsv_sug7=100&inputT=6674&rsv_sug4=6674)；反之，比赛采用[双循环赛制](https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&rsv_idx=1&tn=baidu&wd=%E5%8F%8C%E5%BE%AA%E7%8E%AF%E8%B5%9B%E5%88%B6&fenlei=256&oq=%25E5%258F%258C%25E3%2580%2581%25E5%25BE%25AA%25E7%258E%25AF%25E8%25B5%259B%25E5%2588%25B6&rsv_pq=dbae8bf800eb4a3e&rsv_t=227dPuRnHRW0LLaCwMDnqfxLk4oxV1JBzWcsSfPqlAXHq7nPYwkJU4mwEC0&rqlang=cn&rsv_enter=1&rsv_dl=tb&rsv_btype=t&rsv_sug2=0&rsv_sug3=17&rsv_sug1=11&rsv_sug7=100)。

如果比赛与比赛之间需要相隔 $3$ 天，每天最多只能举行一场比赛，请你帮忙算算一个赛季需要多少天。

## 输入格式

**本题有多组数据。**

第一行输入一个整数 $T$，表示测试数据的数量。

对于每组测试数据：

一行，输入一个正整数 $n$，表示球队的数量。

## 输出格式

对于每组数据，输出一行一个整数，求出一个赛季需要多少天。

## 样例

```input1
3
1
2
3
```

```output1
0
5
21
```

```input2
3
10
100
1000
```

```output2
357
19797
1997997
```

## 样例 1 解释

一支球队踢不了比赛，输出 $0$。

两支球队需要踢 $(1,2),(2,1)$ 两场比赛，分别安排在第 $1,5$ 天，输出 $5$。

三支球队需要踢 $(1,2),(2,1),(1,3),(3,1),(2,3),(3,2)$ 六场比赛，分别安排在第 $1,5,9,13,17,21$ 天，输出 $21$。

## 数据范围

对于 $100\%$ 的数据，$1 \le T \le 50$，$1 \le n \le 10^9$。

本题共有四个等分的子任务，各子任务的特殊限制如下：

1. $n=1$。
2. $n \le 15$。
3. $n \le 10^4$。
4. 无特殊限制。
