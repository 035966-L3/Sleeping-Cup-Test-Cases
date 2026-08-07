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
int main()
{
	freopen("1.in", "wb", stdout);
	puts("1000000");
	for (int i = 0; i <= 499; i++)
		for (int j = 0; j <= 499; j++)
			printf("%d %d\n", i, j);
	for (int i = 999501; i <= 1000000; i++)
		for (int j = 999501; j <= 1000000; j++)
			printf("%d %d\n", i, j);
	for (int i = 1; i <= 500000; i++)
		printf("%llu %llu\n", get() % 1000001, get() % 1000001);
	return 0;
}
