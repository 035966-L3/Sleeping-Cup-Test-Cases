#include <bits/stdc++.h>
using namespace std;
unsigned long long x = 234565432234565432ll;
inline unsigned long long get()
{
	x ^= x << 7;
	x ^= x >> 23;
	x ^= x << 12;
	return x;
}
char s[10];
const int N = 1e5 + 12;
int a[N];
map <long long, bool> p;
int main()
{
	freopen("17.in", "wb", stdout);
	puts("632 199396");
	for (int i = 1; i <= 631; i++)
		for (int j = i + 1; j <= 632; j++)
			printf("%d %d\n", i, j);
	fclose(stdout);
	freopen("18.in", "wb", stdout);
	puts("100000 99999");
	for (int i = 1; i <= 99999; i++)
		printf("%d %d\n", i, min(i + 3, 100000));
	fclose(stdout);
	freopen("19.in", "wb", stdout);
	puts("100000 99999");
	for (int i = 1; i <= 99999; i++)
		printf("%d 100000\n", i);
	fclose(stdout);
	freopen("20.in", "wb", stdout);
	puts("100000 200000");
	for (int i = 10000; i <= 99999; i++)
		printf("%d 100000\n", i);
	for (int i = 90000; i <= 91099; i++)
		for (int j = 91100; j <= 91199; j++)
			printf("%d %d\n", i, j);
	fclose(stdout);
	for (int k = 21; k <= 25; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		int n = 90000 + get() % 10000, m = n - 1;
		printf("%d %d\n", n, m);
		for (int i = 1; i <= n; i++)
		{
			a[i] = i;
			swap(a[i], a[i - get() % i]);
		}
		for (int i = 1; i <= n - 1; i++)
			printf("%d %d\n", min(a[i], a[i + 1]), max(a[i], a[i + 1]));
		fclose(stdout);
	}
	for (int k = 26; k <= 30; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		int n = 100000, m = n - 1;
		printf("%d %d\n", n, m);
		for (int i = 1; i <= n; i++)
		{
			a[i] = i;
			swap(a[i], a[i - get() % i]);
		}
		for (int i = 1; i <= n - 1; i++)
			printf("%d %d\n", min(a[i], a[i + 1]), max(a[i], a[i + 1]));
		fclose(stdout);
	}
	for (int k = 31; k <= 35; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		int n = 90000 + get() % 10000, m = n * 2 / 3;
		printf("%d %d\n", n, m);
		p.clear();
		while (m)
		{
			int u = get() % n + 1, v = get() % n + 1;
			if (u >= v) continue;
			if (p.count(1000000ll * u + v)) continue;
			p[1000000ll * u + v] = true;
			printf("%d %d\n", u, v);
			m--;
		}
		fclose(stdout);
	}
	for (int k = 36; k <= 40; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		int n = 100000, m = n * 2 / 3;
		printf("%d %d\n", n, m);
		p.clear();
		while (m)
		{
			int u = get() % n + 1, v = get() % n + 1;
			if (u >= v) continue;
			if (p.count(1000000ll * u + v)) continue;
			p[1000000ll * u + v] = true;
			printf("%d %d\n", u, v);
			m--;
		}
		fclose(stdout);
	}
	for (int k = 41; k <= 45; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		int n = 90000 + get() % 10000, m = 180000 + get() % 20000;
		printf("%d %d\n", n, m);
		p.clear();
		while (m)
		{
			int u = get() % n + 1, v = get() % n + 1;
			if (u >= v) continue;
			if (p.count(1000000ll * u + v)) continue;
			p[1000000ll * u + v] = true;
			printf("%d %d\n", u, v);
			m--;
		}
		fclose(stdout);
	}
	for (int k = 46; k <= 50; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		int n = 100000, m = 200000;
		printf("%d %d\n", n, m);
		p.clear();
		while (m)
		{
			int u = get() % n + 1, v = get() % n + 1;
			if (u >= v) continue;
			if (p.count(1000000ll * u + v)) continue;
			p[1000000ll * u + v] = true;
			printf("%d %d\n", u, v);
			m--;
		}
		fclose(stdout);
	}
	return 0;
}
