#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 12, M = 6e6 + 12;
int ps[M];
bitset <N> pt;
int main()
{
	freopen("tsp.in", "r", stdin);
	freopen("tsp.out", "w", stdout);
	int n, pp = 0, ans = 6, pi = 4;
	cin >> n;
	if (n <= 8)
	{
		cout << n - 1 << endl;
		return 0;
	}
	for (int i = 2; i <= n; i++)
	{
		if (!pt[i])
		{
			pp++;
			ps[pp] = i;
		}
		for (int j = 1; j <= pp; j++)
		{
			int h = ps[j] * i;
			if (h > n) break;
			pt[h] = true;
			if (i % ps[j] == 0) break;
		}
	}
	ps[pp + 1] = 2 * N;
	for (int i = 8; i <= n; i++)
	{
		if (pi < pp && ps[pi + 1] == i)
		{
			ans += ps[pi + 1] - ps[pi];
			pi++;
			continue;
		}
		if (ps[pi + 1] - i == i - ps[pi]) continue;
		ans += min(ps[pi + 1] - i, i - ps[pi]);
	}
	cout << ans << endl;
	return 0;
}
