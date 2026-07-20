#include <bits/stdc++.h>
using namespace std;
struct Barrett_Reduction
{
	unsigned int m;
	unsigned long long I;
	inline void init(unsigned int p)
	{
		m = p;
		I = ((unsigned __int128) 1 << 64) / m;
	}
	inline unsigned int reduce(unsigned long long a)
	{
		unsigned long long q = ((unsigned __int128) a * I) >> 64;
		unsigned long long r = a - q * m;
		if (r >= m) r -= m;
		return r;
	}
};
struct Miller_Rabin
{
	int power(int a, int b, int p)
	{
		if (b == 1) return a;
		int x = power(a, b >> 1, p);
		x = 1ll * x * x % p;
		if (b & 1) x = 1ll * x * a % p;
		return x;
	}
	inline bool check(int n, int h, int a)
	{
		if (n % a == 0) return false;
		int now = power(a, h, n);
		if (now == 1) return true;
		while (h != n - 1)
		{
			if (now == n - 1) return true;
			now = 1ll * now * now % n;
			h <<= 1;
		}
		return false;
	}
	inline bool prime(int n)
	{
		int h = n - 1;
		while ((h & 1) == 0) h >>= 1;
		if (!check(n, h, 2)) return false;
		if (!check(n, h, 7)) return false;
		if (!check(n, h, 61)) return false;
		return true;
	}
};
struct Hash
{
	string s;
	unsigned long long b;
	Barrett_Reduction p[2];
	vector <unsigned long long> u[2];
	vector <unsigned long long> v[2];
	inline void pre_init()
	{
		Miller_Rabin m;
		random_device r;
		for (int i = -1; i <= 1; i++)
		{
			unsigned int q = 500000000 + i * 200000000 + r() % 100000000;
			while (!m.prime(q)) q++;
			if (i == -1) b = q;
			if (i >= 0) p[i].init(q);
		}
	}
	inline void init()
	{
		for (int i = 0; i <= 1; i++)
		{
			u[i].push_back(p[i].m - 1);
			for (int j = 1; j <= (int) s.size(); j++)
				u[i].push_back(p[i].reduce(u[i].back() * b));
			v[i].push_back(0);
			v[i].push_back(s[0]);
			for (int j = 2; j <= (int) s.size(); j++)
				v[i].push_back(p[i].reduce(v[i].back() * b + s[j - 1]));
		}
	}
	inline unsigned long long query(int l, int r)
	{
		unsigned long long w = p[0].reduce(v[0][r] + v[0][l - 1] * u[0][r - l + 1]);
		w = (w << 32) + p[1].reduce(v[1][r] + v[1][l - 1] * u[1][r - l + 1]);
		return w;
	}
};
Hash s1, s2;
unordered_map <unsigned long long, bool> p;
bool ok(int n, int m)
{
	p.clear();
	for (int i = m + 1; i <= n - m + 1; i++)
	{
		p[s1.query(i - m, i - 1)] = true;
		if (p.count(s2.query(n + 1 - i - m + 1, n + 1 - i))) return true;
	}
	return false;
}
int main()
{
	freopen("backward.in", "r", stdin);
	freopen("backward.out", "w", stdout);
	s1.pre_init();
	s2 = s1;
	cin >> s1.s;
	s1.init();
	s2.s = s1.s;
	reverse(s2.s.begin(), s2.s.end());
	s2.init();
	int n = s1.s.size(), l = 0, r = n / 2;
	while (l < r)
	{
		int m = (l + r + 1) >> 1;
		bool b = ok(n, m);
		if (b) l = m;
		if (!b) r = m - 1;
	}
	cout << l << endl;
	return 0;
}
