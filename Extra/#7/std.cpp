#include <bits/stdc++.h>
using namespace std;
const int N = 30, P = 30, M = N + 12, Q = 2 * N * P + 12;
int b[M], dp[M][Q];
int main()
{
	freopen("python.in", "r", stdin);
	freopen("python.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		memset(dp, 0xc0, sizeof dp);
		int n, m, k, a, c, ans = 0;
		cin >> n >> m >> k >> a;
		__int128 sum = (__int128) m * (__int128) a * (__int128) k;
		if (k > 2 * P) c = P - 1;
		if (k <= 2 * P) c = k;
		a %= P;
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
			sum += b[i];
			b[i] %= P;
		}
		if (2 * m > n)
		{
			for (int i = 1; i <= n; i++)
				b[i] = (b[i] + 1ll * a * k) % P;
			m = n - m;
			a = (P - a) % P;
		}
		dp[0][0] = 0;
		for (int i1 = 1; i1 <= n; i1++)
			for (int i2 = 0; i2 <= min(i1 * c, m * min(k, n * P)); i2++)
				for (int i3 = 0; i3 <= min(i2, c); i3++)
					dp[i1][i2] = max(dp[i1][i2], dp[i1 - 1][i2 - i3] + (b[i1] + a * i3) % P);
		if (k > 2 * P)
			for (int i = 1ll * m * k % P; i <= min(1ll * n * c, 1ll * m * k); i += P)
				ans = max(ans, dp[n][i]);
		if (k <= 2 * P) ans = dp[n][m * k];
		cout << (long long) (4 * ((sum - ans) / P) + 36 * n + 56) << endl;
	}
	return 0;
}
