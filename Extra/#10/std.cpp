#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 12, Real_N = 4e6, P = 1e9 + 7;
int f1[N], f2[N];
int divs(int a, int b, int p)
{
	if (b % a == 0) return b / a;
	int x = divs(p % a, a - b % a, a);
	return (1ll * x * p + b) / a;
}
int C(int m, int n)
{
	if (n < 0 || m < 0 || n < m) return 0;
	return 1ll * f1[n] * f2[m] % P * f2[n - m] % P;
}
int main()
{
	f1[0] = 1;
	for (int i = 1; i <= Real_N; i++)
		f1[i] = 1ll * f1[i - 1] * i % P;
	f2[Real_N] = divs(f1[Real_N], 1, P);
	for (int i = Real_N - 1; i >= 0; i--)
		f2[i] = 1ll * f2[i + 1] * (i + 1) % P;
	int T, a, b, c;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &a, &b);
		c = a + a + b + b;
		printf("%lld\n", (2ll * P + C(c / 2, c) - C(a - 1, c) - C(b - 1, c)) % P);
	}
	return 0;
}
