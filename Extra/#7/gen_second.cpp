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
void generate(int s1, int s2, int s3, int s4, int s5)
{
	int n = rd(30);
	if (s1) n = s1;
	int m = rd(n);
	if (s2 == -1 && n == 1) n = 2;
	if (s2 == -1) m = rd(max(n, 2) / 2);
	if (s2 == -2) m = n + 1 - rd(max(n, 2) / 2);
	if (s2 > 0) m = s2;
	int k = rd(1000000000);
	if (s3 == -1) k = rd(60);
	if (s3 > 0) k = s3;
	int a = rd(1000000000);
	if (s4 == -1) while (__gcd(a, 30) > 1) a = rd(1000000000);
	if (s4 > 0) a = s4;
	cout << n << ' ' << m << ' ' << k << ' ' << a << endl;
	if (s5) cout << s5;
	if (!s5) cout << rd(1000000000);
	for (int i = 2; i <= n; i++)
	{
		if (s5) cout << ' ' << s5;
		if (!s5) cout << ' ' << rd(1000000000);
	}
	cout << endl;
}
int main()
{
	string tc;
	int s1, s2, s3, s4, s5;
	while (cin >> tc >> s1 >> s2 >> s3 >> s4 >> s5)
	{
		tc += ".in";
		freopen(tc.c_str(), "wb", stdout);
		puts("30");
		for (int i = 1; i <= 30; i++)
			generate(s1, s2, s3, s4, s5);
		fclose(stdout);
	}
	return 0;
}
