将方程左右两边都乘上 $1-x-x^2$：

$$1-F_{2n+1}x^{2n}-F_{2n}x^{2n+1}=0$$

$$x^{2n}(F_{2n+1}+F_{2n}x)=1$$

将方程左边设为函数：

$$A(x)=x^{2n}(F_{2n+1}+F_{2n}x)$$

==**（25 分）**==

- $A(0)=0$
- $A\left(\dfrac{\sqrt{5}-1}{2}\right)=1$
- $x \to +\infty$ 时 $A(x) \to +\infty$
- $x > 0$ 时 $A'(x) > 0$

经检验 $x=\dfrac{\sqrt{5}-1}{2}$ 是增根，故方程在 $[0, +\infty)$ 上无实根。

==**（50 分）**==

- $A\left(-\dfrac{F_{2n+1}}{F_{2n}}\right)=0$
- $x < -\dfrac{2nF_{2n+1}}{(2n+1)F_{2n}}$ 时 $A'(x) > 0$

故方程在 $\left(-\infty, -\dfrac{F_{2n+1}}{F_{2n}}\right]$ 上无实根。

==**（75 分）**==

- $A\left(-\dfrac{\sqrt{5}+1}{2}\right)=1$
- $x < -\dfrac{2nF_{2n+1}}{(2n+1)F_{2n}}$ 时 $A'(x) > 0$
- $x = -\dfrac{2nF_{2n+1}}{(2n+1)F_{2n}}$ 时 $A'(x) = 0$
- $x \in \left(-\dfrac{2nF_{2n+1}}{(2n+1)F_{2n}},0\right)$ 时 $A'(x) < 0$
- $-\dfrac{2nF_{2n+1}}{(2n+1)F_{2n}} \in \mathbb Q$
- $-\dfrac{\sqrt{5}+1}{2} \notin \mathbb Q$

经检验 $x=-\dfrac{1+\sqrt{5}}{2}$ 是增根，故方程在 $\left(-\dfrac{F_{2n+1}}{F_{2n}}, 0\right)$ 上有唯一实根。

综上，方程存在唯一实根，命题得证！

==**（100 分）**==
