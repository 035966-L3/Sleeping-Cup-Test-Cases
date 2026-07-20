#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 12, M = 17, B = 10, P = 1e9 + 7;
int p[N], q[N], d[N], b[N], w[N];
long long s[N][M];
pair <int, int> dfs(int l, int r, int n, int c, int e)
{
	if (l > r) return make_pair(0, 0);
	if (l == r) return make_pair((int) (1ll * e * b[d[p[l]] - c] % P), b[d[p[l]] - c]);
	long long u = 0, v = 0;
	int z = w[r - l + 1], t = min(s[l][z], s[r - (1 << z) + 1][z]) / n;
	if (d[p[l]] == t)
	{
		u = e;
		v = b[t - c];
		l++;
	}
	while (l <= r)
	{
		int z = w[r - l + 1];
		long long y = min(s[l][z], s[r - (1 << z) + 1][z]);
		if (y / n != t) break;
		pair <int, int> x = dfs(l, y % n, n, t + 1, 0);
		u = (u + x.first + 1ll * e * (1ll * B * x.second % P + 1) + 1) % P;
		v = (v + 1ll * b[t - c] * (1ll * B * x.second % P + 1)) % P;
		l = y % n + 2;
		e++;
	}
	pair <int, int> x = dfs(l, r, n, t + 1, 0);
	u = (u + x.first + 1ll * e * B % P * x.second % P) % P;
	v = (v + 1ll * b[t - c] * B % P * x.second % P) % P;
	return make_pair(u, v);
}
int main()
{
	freopen("seminar.in", "r", stdin);
	freopen("seminar.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0, j = 1; j <= n; i++, j <<= 1)
		w[j] = i;
	for (int i = 3; i <= n; i++)
		if (!w[i]) w[i] = w[i - 1];
	b[0] = 1;
	for (int i = 1; i <= n; i++)
		b[i] = 1ll * b[i - 1] * B % P;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= n; i++)
		q[p[i]] = i;
	d[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1];
		if (q[i] < q[i - 1]) d[i]++;
	}
	for (int i = 1; i <= n; i++)
		s[i][0] = 1ll * d[p[i]] * n + i - 1;
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			s[i][j] = min(s[i][j - 1], s[i + (1 << (j - 1))][j - 1]);
	cout << dfs(1, n, n, 1, 1).first << endl;
	return 0;
}
