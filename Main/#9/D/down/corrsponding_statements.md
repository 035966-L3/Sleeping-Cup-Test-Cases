## 题目描述

规定 $x$ 为实数，考虑斐波那契（Fibonacci）数列的普通生成函数（OGF）的一个变体（将原函数除以 $x$）：

$$\begin{aligned}f(x)&=\dfrac{1}{1-x-x^2}\\&=\sum_{i=1}^\infty\dfrac{\left(\dfrac{1+\sqrt{5}}{2}\right)^i-\left(\dfrac{1-\sqrt{5}}{2}\right)^i}{\sqrt{5}} x^{i-1}\\&=1+x+2x^2+3x^3+5x^4+8x^5+\ldots\end{aligned}$$

进一步地，考虑截取其幂级数形式（上面等式的最后一行）的前 $2n$ 项（$n$ 为正整数），记为 $g_n(x)$：

$$\begin{aligned}g_n(x)&=\dfrac{1}{1-x-x^2} \mod x^{2n}\\&=\sum_{i=1}^{2n}\dfrac{\left(\dfrac{1+\sqrt{5}}{2}\right)^i-\left(\dfrac{1-\sqrt{5}}{2}\right)^i}{\sqrt{5}} x^{i-1}\\&=1+x+2x^2+3x^3+5x^4+8x^5+\ldots+\dfrac{\left(\dfrac{1+\sqrt{5}}{2}\right)^{2n}-\left(\dfrac{1-\sqrt{5}}{2}\right)^{2n}}{\sqrt{5}} x^{2n-1}\end{aligned}$$

更进一步地，可以证明 $g_n(x)$ 在任意正整数 $n$ 下均存在唯一零点（即满足 $g_n(x)=0$ 的实数），记为 $h(n)$。

再进一步地，可以证明 $h(n)$ 在 $n$ 趋近于无穷大时收敛于某一确定实数 $R$。

请求出实数 $R$ 的值，然后四舍五入保留 $10$ 位小数，提交你的答案：

{{ input(1) }}
