#include <bits/stdc++.h>
using namespace std;
unsigned long long x = 654323456234565432ll;
inline unsigned long long get()
{
	x ^= x << 7;
	x ^= x >> 23;
	x ^= x << 12;
	return x;
}
bool have(long double p)
{
	return get() <= p * ULLONG_MAX;
}
int a[10012];
void gen(int c, long double p, bool o)
{
	int l = c - 1, r = c + 1, v = 9999, u = 1;
	a[c] = 10000;
	while (l >= 1 || r <= 10000)
	{
		if (l == 0)
		{
			a[r] = v;
			v--;
			r++;
			continue;
		}
		if (r == 10001)
		{
			a[l] = v;
			v--;
			l--;
			continue;
		}
		bool w = have(p);
		u = 1;
		if (o)
		{
			if (w) u = get() % max(l / 2, 1) + 1;
			if (!w) u = get() % max((10001 - r) / 2, 1) + 1;
		}
		while (u--)
		{
			if (!w)
			{
				a[r] = v;
				v--;
				r++;
			}
			if (w)
			{
				a[l] = v;
				v--;
				l--;
			}
		}
	}
}
void output()
{
	for (int i = 1; i <= 9999; i++)
		cout << a[i] << ' ';
	cout << a[10000] << endl;
}
int main()
{
	freopen("1.in", "wb", stdout);
	int t;
	while (cin >> t)
	{
		gen(t, 0, 0);
		output();
		gen(t, 1, 0);
		output();
		gen(t, 0.5, 0);
		output();
		gen(t, (t + 1) / 9999.0, 0);
		output();
		gen(t, 0.5, 1);
		output();
	}
	return 0;
}
