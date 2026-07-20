#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 12, M = 4e5 + 12;
struct F
{
	int to[M], ns[M], fs[N], m;
	void add(int f, int t)
	{
		m++;
		to[m] = t;
		ns[m] = fs[f];
		fs[f] = m;
	}
};
F f;
int sp[N];
int bfs(int x, int y, int n)
{
	for (int i = 1; i <= n; i++)
		sp[i] = 1e9;
	queue <int> q;
	sp[x] = 0;
	q.push(x);
	while (!q.empty())
	{
		int w = q.front();
		q.pop();
		int ii = f.fs[w];
		while (ii)
		{
			if (sp[f.to[ii]] == 1e9)
			{
				sp[f.to[ii]] = sp[w] + 1;
				q.push(f.to[ii]);
			}
			ii = f.ns[ii];
		}
	}
	return sp[y];
}
int main()
{
	freopen("voucher.in", "r", stdin);
	freopen("voucher.out", "w", stdout);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		f.add(u, v);
		f.add(v, u);
	}
	int a = 1e9;
	a = min(a, bfs(1, 2, n));
	a = min(a, bfs(1, 3, n));
	a = min(a, bfs(2, 3, n));
	if (a == 1e9) a = -1;
	cout << a << endl;
	return 0;
}
