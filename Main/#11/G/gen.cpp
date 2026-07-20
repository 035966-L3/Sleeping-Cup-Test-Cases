#include <bits/stdc++.h>
using namespace std;
char s[10];
unsigned long long x = 234565432234565432ll;
inline unsigned long long get()
{
	x ^= x << 7;
	x ^= x >> 23;
	x ^= x << 12;
	return x;
}
const int N = 1e5 + 12;
int a[N];
int main()
{
	freopen("37.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 99999; i++)
		printf("%d ", i);
	puts("100000");
	fclose(stdout);
	freopen("38.in", "wb", stdout);
	puts("100000");
	for (int i = 100000; i >= 2; i--)
		printf("%d ", i);
	puts("1");
	fclose(stdout);
	freopen("39.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 99999; i += 2)
		printf("%d ", i);
	for (int i = 100000; i >= 4; i -= 2)
		printf("%d ", i);
	puts("2");
	fclose(stdout);
	freopen("40.in", "wb", stdout);
	puts("100000");
	for (int i = 99999; i >= 1; i -= 2)
		printf("%d ", i);
	for (int i = 2; i <= 99998; i += 2)
		printf("%d ", i);
	puts("100000");
	fclose(stdout);
	freopen("41.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 49999; i++)
		printf("%d %d ", i, i + 50000);
	puts("50000 100000");
	fclose(stdout);
	freopen("42.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 49999; i++)
		printf("%d %d ", i, 100001 - i);
	puts("50000 50001");
	fclose(stdout);
	freopen("43.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 49999; i++)
		printf("%d %d ", 50001 - i, i + 50000);
	puts("1 100000");
	fclose(stdout);
	freopen("44.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 49999; i++)
		printf("%d %d ", 50001 - i, 100001 - i);
	puts("1 50001");
	fclose(stdout);
	freopen("45.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 49997; i += 2)
		printf("%d %d %d %d ", i, i + 1, i + 50000, i + 50001);
	puts("49999 50000 99999 100000");
	fclose(stdout);
	freopen("46.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 49997; i += 2)
		printf("%d %d %d %d ", i, i + 1, 100001 - i, 100000 - i);
	puts("49999 50000 50002 50001");
	fclose(stdout);
	freopen("47.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 49997; i += 2)
		printf("%d %d %d %d ", 50001 - i, 50000 - i, i + 50000, i + 50001);
	puts("2 1 99999 100000");
	fclose(stdout);
	freopen("48.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 49997; i += 2)
		printf("%d %d %d %d ", 50001 - i, 50000 - i, 100001 - i, 100000 - i);
	puts("2 1 50002 50001");
	fclose(stdout);
	for (int k = 49; k <= 53; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		int n = 90000 + get() % 10000;
		printf("%d\n", n);
		for (int i = 1; i <= n; i++)
		{
			a[i] = i;
			swap(a[i], a[i - get() % min(i, 500)]);
		}
		for (int i = 1; i <= n - 1; i++)
			printf("%d ", a[i]);
		printf("%d\n", a[n]);
		fclose(stdout);
	}
	for (int k = 54; k <= 58; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		int n = 90000 + get() % 10000;
		printf("%d\n", n);
		for (int i = 1; i <= n; i++)
		{
			a[i] = i;
			swap(a[i], a[i - get() % min(i, 500)]);
		}
		reverse(a + 1, a + n + 1);
		for (int i = 1; i <= n - 1; i++)
			printf("%d ", a[i]);
		printf("%d\n", a[n]);
		fclose(stdout);
	}
	for (int k = 59; k <= 63; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		int n = 90000 + get() % 10000;
		printf("%d\n", n);
		for (int i = 1; i <= n; i++)
		{
			a[i] = i;
			swap(a[i], a[i - get() % i]);
		}
		for (int i = 1; i <= n - 1; i++)
			printf("%d ", a[i]);
		printf("%d\n", a[n]);
		fclose(stdout);
	}
	return 0;
}
