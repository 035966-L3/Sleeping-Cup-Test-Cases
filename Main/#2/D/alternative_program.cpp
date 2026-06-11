#include <bits/stdc++.h>
using namespace std;
const int K = 250;
const int L = K + 12;
const int M = K * K + 12;
const int N = 4 * K * K + 12;
const int P = 16;
const int O = 0xffff;
const int D = 4 * K * K * P + 2 * O + 12;
const int C = 2 * K * K + 12;
pair<unsigned short, unsigned short> e[N];
pair<unsigned char, unsigned char> at[M];
unsigned short alt[L][L];
unsigned short eto[M];
int k;
int q;
int ec = 0;
int now = 0;
struct U
{
	unsigned short a[D];
	unsigned short ll[D];
	unsigned short rr[D];
	int l[D];
	int r[D];
	int roots[C];
	int ts;
	int st;
	void init(int n)
	{
		ts = n;
		st = n;
		for (int i = 1; i <= n; i++)
			rr[i] = (1 << P) - 1;
		for (int i = 1; i <= n; i++)
			roots[i] = i;
	}
	void expand(int b)
	{
		if (ll[b] == rr[b]) return;
		if (l[b] == 0)
		{
			ts++;
			a[ts] = 0;
			ll[ts] = ll[b];
			rr[ts] = (ll[b] + rr[b]) >> 1;
			l[ts] = 0;
			r[ts] = 0;
			l[b] = ts;
		}
		if (r[b] == 0)
		{
			ts++;
			a[ts] = 0;
			ll[ts] = ((ll[b] + rr[b]) >> 1) + 1;
			rr[ts] = rr[b];
			l[ts] = 0;
			r[ts] = 0;
			r[b] = ts;
		}
	}
	bool create(int x, int b)
	{
		if (ll[b] == x && rr[b] == x) return true;
		expand(b);
		int lmid = (ll[b] + rr[b]) >> 1;
		int rmid = lmid + 1;
		if (x <= lmid) return create(x, l[b]);
		if (x >= rmid) return create(x, r[b]);
	}
	bool add(int x, int y, int b, int c)
	{
		if (b != c) a[b] += a[c] + y;
		if (b == c) a[b] += y;
		if (ll[b] == x && rr[b] == x) return true;
		int lmid = (ll[b] + rr[b]) >> 1;
		int rmid = lmid + 1;
		if (x <= lmid) r[b] = r[c];
		if (x >= rmid) l[b] = l[c];
		expand(b);
		if (x <= lmid) return add(x, y, l[b], l[c]);
		if (x >= rmid) return add(x, y, r[b], r[c]);
	}
	int get(int l, int r, int b)
	{
		if (!b) return 0;
		if (l == ll[b] && r == rr[b]) return a[b];
		int lmid = (ll[b] + rr[b]) >> 1;
		int rmid = lmid + 1;
		if (r <= lmid) return get(l, r, this -> l[b]);
		if (l >= rmid) return get(l, r, this -> r[b]);
		return get(l, lmid, this -> l[b]) + get(rmid, r, this -> r[b]);
	}
};
U t;
struct T
{
	unsigned short x;
	unsigned short y;
	unsigned short a;
};
struct R
{
	unsigned short ld[M];
	unsigned short sz[M];
	unsigned short mina[M];
	void init()
	{
		for (unsigned short i = 1; i <= k * k; i++)
		{
			ld[i] = i;
			sz[i] = 1;
		}
		for (unsigned char i = 1; i <= k; i++)
			for (unsigned char j = 1; j <= k; j++)
				mina[(i - 1) * k + j] = alt[i][j];
	}
	unsigned short get(unsigned short x)
	{
		if (ld[x] == x) return x;
		ld[x] = get(ld[x]);
		return ld[x];
	}
	T mrg(int x, int y)
	{
		x = this -> get(x);
		y = this -> get(y);
		if (x == y) return (T) {O, O, O};
		unsigned short xx = sz[x];
		unsigned short yy = sz[y];
		if (xx < yy)
		{
			swap(x, y);
			swap(xx, yy);
		}
		T res;
		if (mina[x] < mina[y]) res = (T) {mina[x], mina[y], sz[y]};
		if (mina[x] > mina[y]) res = (T) {mina[y], mina[x], sz[x]};
		ld[y] = x;
		sz[x] = xx + yy;
		sz[y] = 0;
		mina[x] = min(mina[x], mina[y]);
		mina[y] = O;
		return res;
	}
};
R rt;
int main()
{
	ios::sync_with_stdio(0);
	cin >> k >> q;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			cin >> alt[i][j];
	for (int i = 0; i <= k + 1; i++)
		alt[0][i] = O;
	for (int i = 0; i <= k + 1; i++)
		alt[k + 1][i] = O;
	for (int i = 0; i <= k + 1; i++)
		alt[i][0] = O;
	for (int i = 0; i <= k + 1; i++)
		alt[i][k + 1] = O;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			at[alt[i][j]] = make_pair(i, j);
	for (int i = 0; i <= k * k - 1; i++)
	{
		int x = at[i].first;
		int y = at[i].second;
		if (alt[x][y + 1] < alt[x][y])
		{
			ec++;
			e[ec] = make_pair((x - 1) * k + y, (x - 1) * k + (y + 1));
		}
		if (alt[x][y - 1] < alt[x][y])
		{
			ec++;
			e[ec] = make_pair((x - 1) * k + y, (x - 1) * k + (y - 1));
		}
		if (alt[x + 1][y] < alt[x][y])
		{
			ec++;
			e[ec] = make_pair((x - 1) * k + y, x * k + y);
		}
		if (alt[x - 1][y] < alt[x][y])
		{
			ec++;
			e[ec] = make_pair((x - 1) * k + y, (x - 2) * k + y);
		}
	}
	rt.init();
	t.init(2 * k * k - 1);
	for (int i = 0; i <= O; i++)
		t.create(i, t.roots[2 * k * k - 1]);
	for (int i = 0; i <= O; i++)
		t.add(i, 1, t.roots[2 * k * k - 1], t.roots[2 * k * k - 1]);
	t.roots[0] = t.roots[2 * k * k - 1];
	for (int i = 1; i <= ec; i++)
	{
		T res = rt.mrg(e[i].first, e[i].second);
		if (res.a != O)
		{
			now++;
			t.add(res.y, -res.a, t.roots[2 * now - 1], t.roots[2 * now - 2]);
			t.add(res.x, res.a, t.roots[2 * now], t.roots[2 * now - 1]);
		}
		eto[alt[(e[i].first - 1) / k + 1][(e[i].first - 1) % k + 1]] = now;
	}
	for (int i = 1; i <= k * k - 1; i++)
		eto[i] = max(eto[i], eto[i - 1]);
	while (q--)
	{
		int x;
		int y;
		cin >> x >> y;
		cout << y - t.get(0, x, t.roots[2 * eto[y - 1]]) << endl;
	}
	return 0;
}
