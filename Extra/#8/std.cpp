#include <bits/stdc++.h>
using namespace std;
const int N = 1.01e6 + 12, M = 2e5 + 12;
int pp = 0, ps[M], pa[N];
bitset <N> pt;
int main()
{
	freopen("triples.in", "r", stdin);
	freopen("triples.out", "w", stdout);
	long long n;
	cin >> n;
	if (n <= 299)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 2; i <= sqrtl(n + 0.5) + 10000; i++)
	{
		if (!pt[i])
		{
			pp++;
			ps[pp] = i;
		}
		for (int j = 1; j <= pp; j++)
		{
			int h = ps[j] * i;
			if (h > sqrtl(n + 0.5) + 10000) break;
			pt[h] = true;
			if (i % ps[j] == 0) break;
		}
	}
	for (int i = 2; i <= sqrtl(n + 0.5) + 10000; i++)
		pa[i] = pa[i - 1] + (!pt[i]);
	int ans = 0;
	for (int i = 1; 1ll * ps[i] * ps[i] * ps[i + 1] * ps[i + 2] * ps[i + 2] <= n; i++)
		for (int j = i + 1; 1ll * ps[i] * ps[i] * ps[j] * ps[j + 1] * ps[j + 1] <= n; j++)
			ans += pa[(int) (sqrtl(n / ps[i] / ps[i] / ps[j] + 0.5))] - pa[ps[j]];
	cout << ans << endl;
	return 0;
}
