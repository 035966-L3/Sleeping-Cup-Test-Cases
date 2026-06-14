我们显然可以做到 $O(1)$ 计算 $f(R)$。

公式：

$$
\begin{aligned}
\text{get}(l,r) =\ &C_r A_r^2 - C_r D_r - B_r A_r^2 + B_r D_r - A_r^4 + A_r^2 D_r + (r+1) A_r^3 - (r+1) A_r D_r \\
&+ E_r A_r - G_r + D_r A_r^2 - H_r A_r - (r+1) D_r A_r + (r+1) H_r - F_r A_r + I_r \\
&- C_r A_r A_{l-1} + B_r A_r A_{l-1} + A_r^3 A_{l-1} - (r+1) A_r^2 A_{l-1} - E_r A_{l-1} - D_r A_r A_{l-1} \\
&+ (r+1) D_r A_{l-1} + F_r A_{l-1} \\
&+ C_r D_{l-1} - B_r D_{l-1} - A_r^2 D_{l-1} + (r+1) A_r D_{l-1} + G_{l-1} + H_{l-1} A_r - (r+1) H_{l-1} - I_{l-1}
\end{aligned}
$$

其中：

$$A_i=\sum_{j=1}^i[s_j=\bm{3}]$$

$$B_i=\sum_{j=1}^ij\cdot[s_j=\bm{3}]$$

$$C_i=\sum_{j=1}^ia_{j-1}\cdot[s_j=\bm{3}]$$

$$D_i=\sum_{j=1}^ia_{j}\cdot[s_j=\bm{3}]$$

$$E_i=\sum_{j=1}^ib_{j}\cdot[s_j=\bm{3}]$$

$$F_i=\sum_{j=1}^ic_j\cdot[s_j=\bm{3}]$$
$$G_i=\sum_{j=1}^ie_j\cdot[s_j=\bm{3}]$$
$$H_i=\sum_{j=1}^id_j\cdot[s_j=\bm{3}]$$
$$I_i=\sum_{j=1}^if_j\cdot[s_j=\bm{3}]$$

剩下的，若 $[l,r]$ 成立，$[l,r+1]$ 成立，双指针。

（题解和代码来自 UnionRE）
