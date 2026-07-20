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
int main()
{
	freopen("7.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 99999; i++)
		printf("1000000000 ");
	puts("1000000000");
	fclose(stdout);
	freopen("8.in", "wb", stdout);
	puts("100000");
	printf("999999999 ");
	for (int i = 2; i <= 99999; i++)
		printf("1 ");
	puts("1");
	fclose(stdout);
	freopen("9.in", "wb", stdout);
	puts("100000");
	printf("999999999 ");
	for (int i = 2; i <= 99999; i++)
		printf("1 ");
	puts("2");
	fclose(stdout);
	freopen("10.in", "wb", stdout);
	puts("100000");
	for (int i = 1; i <= 99999; i++)
		printf("%d ", get() % 1000000000 + 1);
	printf("%d\n", get() % 1000000000 + 1);
	fclose(stdout);
}
