## 注意

**本题需要文件读写（`savings.in` / `savings.out`）。**

**本题的题目背景仅供引出题意，请不要过度解读。**

## 题目背景

> 最近，一个源自网络游戏的术语 ——「斩杀线」，正在中文互联网上流行，成为观察美国社会困境的一个形象隐喻。它描述的不是赤贫，而是一种抗风险能力被压榨到极致的普遍状态：众多虽有工作但积蓄微薄的美国家庭，一旦遭遇失业、重病等意外，财务状况便可能「血条见底」，触发失去住房、信用破产的灾难性坠落。官方数据显示，2024 年美国无家可归者超过 77 万人，同比激增 18.1%，其中不乏有正式工作者，显示其社会安全网存在巨大漏洞。「斩杀线」形象揭示了美国社会结构性的经济脆弱。
>
> —— 钟言《「斩杀线」上的美国政治困局》
>
> （资料来源：<https://www.qstheory.cn/20260104/0a091946537a4ea789a07bd4e40253b3/c.html>）

这太恐怖了！Sleeping Iguana 和它的好朋友 Sleeping Alligator 看到这一报道，决定从今开始存钱，为此它们从杂物间里翻出了两只尘封已久的空存钱罐。

## 题目描述

Sleeping Iguana 和 Sleeping Alligator 有两只空存钱罐，其中较大的那只最多能装下 $n$ 枚硬币，较小的那只最多能装下 $m$ 枚硬币。

它们决定在接下来的一段时间里轮流负责存钱，其中第一天的存钱工作由 Sleeping Iguana 负责。具体来说，对于每天的存钱工作，负责方需要执行以下两种操作中的某一种：

- 选择一只存钱罐，向存钱罐里投入一枚硬币。
- 将一只存钱罐里的硬币全部倒进另一只存钱罐 —— 执行这一操作时，要求两只存钱罐在操作前都不是空的。

当某个操作导致硬币溢出存钱罐时，对应的负责方将不得不购买一个新的存钱罐以容纳溢出的硬币。

那么谁存在确保自己不需要购买新存钱罐的操作策略呢？

## 输入格式

**本题有多组测试数据。**

第一行输入一个正整数 $T$，表示测试数据的数量。

接下来，对于每组测试数据，输入一行两个正整数 $n, m$。

## 输出格式

对于每组测试数据，输出一行一个字符串，表示存在确保自己不需要购买新存钱罐的操作策略的那一方的名字。

## 样例

```input1
21
1 1
2 1
2 2
3 1
3 2
3 3
4 1
4 2
4 3
4 4
5 1
5 2
5 3
5 4
5 5
6 1
6 2
6 3
6 4
6 5
6 6
```

```output1
Sleeping Alligator
Sleeping Iguana
Sleeping Alligator
Sleeping Iguana
Sleeping Iguana
Sleeping Alligator
Sleeping Alligator
Sleeping Iguana
Sleeping Alligator
Sleeping Iguana
Sleeping Iguana
Sleeping Alligator
Sleeping Iguana
Sleeping Iguana
Sleeping Iguana
Sleeping Iguana
Sleeping Iguana
Sleeping Alligator
Sleeping Alligator
Sleeping Alligator
Sleeping Alligator
```

## 样例解释

本样例将作为子任务 1 的首个测试点参与评测。

对于第 5 组测试数据，Sleeping Iguana 的一个确保自己不需要购买新存钱罐的操作策略为：

- Sleeping Iguana 向较大的存钱罐里投入一枚硬币。
- Sleeping Iguana 观察 Sleeping Alligator 接下来的操作：
   - 如果 Sleeping Alligator 向较大的存钱罐里投入一枚硬币：
      - Sleeping Iguana 向较大的存钱罐里投入一枚硬币。
      - Sleeping Alligator 此时只能向较小的存钱罐里投入一枚硬币。
      - Sleeping Iguana 向较小的存钱罐里投入一枚硬币。
      - 此时两个存钱罐都恰好装满，Sleeping Alligator 不得不购买一个新的存钱罐。
   - 如果 Sleeping Alligator 向较小的存钱罐里投入一枚硬币：
      - Sleeping Iguana 拿起较大的存钱罐，将里面的硬币全部倒进较小的存钱罐。
      - Sleeping Alligator 此时只能向较大的存钱罐里投入一枚硬币。
      - Sleeping Iguana 拿起较小的存钱罐，将里面的硬币全部倒进较大的存钱罐。
      - Sleeping Alligator 此时只能向较小的存钱罐里投入一枚硬币。
      - Sleeping Iguana 向较小的存钱罐里投入一枚硬币。
      - 此时两个存钱罐都恰好装满，Sleeping Alligator 不得不购买一个新的存钱罐。
   - 可以证明，Sleeping Alligator 接下来的操作只能是以上两种之一。

## 数据范围

对于所有子任务：

- $1 \le T \le 10^5$。
- $1 \le m \le n \le 10^9$。
- 每个子任务中有且只有一个测试点。
- 评测时使用的每组测试数据均从所有合法的测试数据中等概率抽取。

本题共有 4 个等分的子任务，各子任务的特殊限制如下：

1. 保证本子任务中测试点的输入数据与样例输入相同。
2. $m = 1$。
3. $m = n$。
4. 无特殊限制。

其中子任务 4 依赖于其他所有子任务。
