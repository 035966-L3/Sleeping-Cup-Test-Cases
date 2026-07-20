#include <bits/stdc++.h>
using namespace std;
char s[10];
unsigned long long x = 654323456654323456ll;
inline unsigned long long get()
{
	x ^= x << 7;
	x ^= x >> 23;
	x ^= x << 12;
	return x;
}
const int N = 1000 + 12;
int p[N], a[N], b[N], c[N];
void output()
{
	for (int i = 1; i <= 1000; i++)
	{
		b[i] = i;
		swap(b[i], b[i - get() % i]);
	}
	for (int i = 1; i <= 1000; i++)
		c[b[i]] = i;
	for (int i = 1; i <= 1000; i++)
		a[i] = c[p[i]];
	for (int i = 1; i <= 999; i++)
		cout << a[i] << ' ';
	cout << a[1000] << endl;
	for (int i = 1; i <= 999; i++)
		cout << b[i] << ' ';
	cout << b[1000] << endl;
	fclose(stdout);
}
int main()
{
	freopen("1.in", "wb", stdout);
	for (int i = 1; i <= 1000; i++)
		p[i] = i;
	output();
	freopen("2.in", "wb", stdout);
	for (int i = 1; i <= 1000; i++)
		p[i] = 1001 - i;
	output();
	freopen("3.in", "wb", stdout);
	for (int i = 1; i <= 500; i++)
		p[i] = 2 * i - 1;
	for (int i = 501; i <= 1000; i++)
		p[i] = 2002 - 2 * i;
	output();
	freopen("4.in", "wb", stdout);
	for (int i = 1; i <= 500; i++)
		p[i] = 1001 - 2 * i;
	for (int i = 501; i <= 1000; i++)
		p[i] = 2 * i - 1000;
	output();
	freopen("5.in", "wb", stdout);
	for (int i = 1; i <= 500; i++)
	{
		p[2 * i - 1] = i;
		p[2 * i] = 500 + i;
	}
	output();
	freopen("6.in", "wb", stdout);
	for (int i = 1; i <= 500; i++)
	{
		p[2 * i - 1] = i;
		p[2 * i] = 1001 - i;
	}
	output();
	freopen("7.in", "wb", stdout);
	for (int i = 1; i <= 500; i++)
	{
		p[2 * i - 1] = 501 - i;
		p[2 * i] = 500 + i;
	}
	output();
	freopen("8.in", "wb", stdout);
	for (int i = 1; i <= 500; i++)
	{
		p[2 * i - 1] = 501 - i;
		p[2 * i] = 1001 - i;
	}
	output();
	for (int k = 9; k <= 12; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		for (int i = 1; i <= 1000; i++)
		{
			p[i] = i;
			swap(p[i], p[i - get() % min(i, 10)]);
		}
		output();
	}
	for (int k = 13; k <= 16; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		for (int i = 1; i <= 1000; i++)
		{
			p[i] = i;
			swap(p[i], p[i - get() % min(i, 10)]);
		}
		reverse(p + 1, p + 1001);
		output();
	}
	for (int k = 17; k <= 20; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		for (int i = 1; i <= 1000; i++)
		{
			p[i] = i;
			swap(p[i], p[i - get() % i]);
		}
		output();
	}
	return 0;
}
