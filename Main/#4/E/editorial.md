若某个 01 串 $A$ 不满足第二个条件：

$$A_1\sharp(A_2\sharp(A_3\sharp(\cdots\sharp(A_{N-1}\sharp A_N))))=0$$

$$A_2\sharp(A_3\sharp(\cdots\sharp(A_{N-1}\sharp A_N)))=0\ (A_1=1)$$

$$A_3\sharp(\cdots\sharp(A_{N-1}\sharp A_N))=0\ (A_2=1)$$

$$\ldots$$

$$A_{N-1}\sharp A_N=0$$

因此只有 $S=\tt{111\ldots110}$ 不满足第二个条件。很明显，$S$ 同时也不满足第一个条件，所以第二个条件实际上是多余的。

对于第一个条件，设答案为 $f(N)$：

- 如果 $A_N=1$，那么一定满足条件，共有 $2^{N-1}$ 个合法 01 串；
- 如果 $A_N=0$，那么需要有 $((((A_1\sharp A_2)\sharp A_3)\sharp\cdots)\sharp A_{N-2})\sharp A_{N-1}=0$，共有 $2^{N-1}-f(N-1)$ 个合法 01 串。

结合 $f(1)=1$，我们得到了 $f(N)$ 的递推公式：

$$f(N)=\begin{cases}1,&N=1\\2^N-f(N-1),&N\ge 2\end{cases}$$

由数学归纳法即可证明通项公式。
