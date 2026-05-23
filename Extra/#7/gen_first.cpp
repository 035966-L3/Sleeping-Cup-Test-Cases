#include <bits/stdc++.h>
using namespace std;
unsigned long long x = 813699126813699126ll;
unsigned long long get()
{
	x ^= x << 7;
	x ^= x >> 23;
	x ^= x << 12;
	return x;
}
int rd(int n)
{
	return get() % n + 1;
}
int main()
{
	freopen("1.in", "wb", stdout);
	puts("30");
	for (int _ = 1; _ <= 30; _++)
	{
		int n = rd(30), m = rd(n), ak = rd(28), k = 1, a = rd(ak);
		while (ak % a) a = rd(ak);
		k = ak / a;
		cout << n << ' ' << m << ' ' << k << ' ' << a << endl;
		cout << rd(29 - ak);
		for (int i = 2; i <= n; i++)
			cout << ' ' << rd(29 - ak);
		cout << endl;
	}
	fclose(stdout);
	freopen("2.in", "wb", stdout);
	puts("30");
	for (int _ = 1; _ <= 30; _++)
	{
		int n = rd(30), m = rd(n), k = rd(10000), a = 30 * rd(33333333);
		cout << n << ' ' << m << ' ' << k << ' ' << a << endl;
		cout << rd(1000000000);
		for (int i = 2; i <= n; i++)
			cout << ' ' << rd(1000000000);
		cout << endl;
	}
	fclose(stdout);
	freopen("3.in", "wb", stdout);
	puts("30");
	for (int _ = 1; _ <= 30; _++)
	{
		int n = rd(30), m = n, k = rd(10000), a = rd(1000000000);
		cout << n << ' ' << m << ' ' << k << ' ' << a << endl;
		cout << rd(1000000000);
		for (int i = 2; i <= n; i++)
			cout << ' ' << rd(1000000000);
		cout << endl;
	}
	fclose(stdout);
	freopen("4.in", "wb", stdout);
	puts("30");
	for (int _ = 1; _ <= 30; _++)
	{
		int n = rd(30), m = rd(n), k = 1, a = rd(1000000000);
		cout << n << ' ' << m << ' ' << k << ' ' << a << endl;
		cout << rd(1000000000);
		for (int i = 2; i <= n; i++)
			cout << ' ' << rd(1000000000);
		cout << endl;
	}
	fclose(stdout);
	freopen("5.in", "wb", stdout);
	puts("30");
	for (int _ = 1; _ <= 30; _++)
	{
		int n = rd(30), m = 1, k = rd(10000), a = rd(1000000000);
		cout << n << ' ' << m << ' ' << k << ' ' << a << endl;
		cout << rd(1000000000);
		for (int i = 2; i <= n; i++)
			cout << ' ' << rd(1000000000);
		cout << endl;
	}
	fclose(stdout);
	return 0;
}
