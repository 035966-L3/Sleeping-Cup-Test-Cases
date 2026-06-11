#include <bits/stdc++.h>
using namespace std;
const int B1 = 320, B2 = 320, C1 = B1 + 12, C2 = B2 + 12, N = 1e5 + 12;
int a[N], b[C2][N], t[C2];
void push(int c)
{
	if (!t[c]) return;
	for (int i = 0; i < B1; i++)
	{
		b[c][a[c * B1 + i]] = 0;
		a[c * B1 + i] = t[c];
	}
	b[c][t[c]] = B1;
	t[c] = 0;
}
int get(int c, int v)
{
	if (t[c] == v) return B1;
	if (t[c] && t[c] != v) return 0;
	return b[c][v];
}
void update(int x, int v)
{
	b[x / B1][a[x]]--;
	a[x] = v;
	b[x / B1][v]++;
}
int main()
{
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
	ios::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i / B1][a[i]]++;
	}
	while (q--)
	{
		int z, m, x, y, l, r, v, f = 0;
		cin >> z;
		if (z == 1)
		{
			cin >> l >> r >> v;
			if (l / B1 == r / B1)
			{
				push(l / B1);
				for (int i = l; i <= r; i++)
					update(i, v);
				continue;
			}
			push(l / B1);
			for (int i = l; i < B1 * (l / B1 + 1); i++)
				update(i, v);
			for (int i = l / B1 + 1; i < r / B1; i++)
				t[i] = v;
			push(r / B1);
			for (int i = r / B1 * B1; i <= r; i++)
				update(i, v);
		}
		if (z == 2)
		{
			cin >> m;
			while (m--)
			{
				cin >> x >> y;
				if (f > n + 1) continue;
				while (f % B1)
				{
					if (a[f] == x) y--;
					f++;
					if (!y) break;
					if (f > n + 1) break;
				}
				if (!y) continue;
				while (f <= n + 1 && y > get(f / B1, x))
				{
					y -= get(f / B1, x);
					f += B1;
				}
				if (f > n + 1) continue;
				push(f / B1);
				while (y)
				{
					if (a[f] == x) y--;
					f++;
				}
			}
			if (f <= n + 1) puts("Yes");
			if (f > n + 1) puts("No");
		}
	}
	return 0;
}
