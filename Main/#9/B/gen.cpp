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
	freopen("2.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 100000; i++)
	{
		int x = rd(1000000000);
		cout << x << ' ' << 1 << endl;
	}
	fclose(stdout);
	freopen("3.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 100000; i++)
	{
		int x = rd(1000000000);
		cout << x << ' ' << x << endl;
	}
	fclose(stdout);
	freopen("4.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 100000; i++)
	{
		int x = rd(1000000000), y = rd(1000000000);
		if (x < y) swap(x, y);
		cout << x << ' ' << y << endl;
	}
	fclose(stdout);
	return 0;
}
