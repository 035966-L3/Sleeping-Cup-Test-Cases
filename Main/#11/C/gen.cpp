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
int main()
{
	for (int k = 2; k <= 51; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		puts("100 100");
		for (int i = 1; i <= 5; i++)
		{
			int x = get() % 100 + 1, y = get() % 1023 + 1;
			for (int j = 1; j <= 20; j++)
				printf("%d %d\n", x, y);
		}
		fclose(stdout);
	}
	for (int k = 52; k <= 56; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		puts("100 100");
		for (int i = 1; i <= 100; i++)
			printf("%d %d\n", get() % 100 + 1, get() % 1023 + 1);
		fclose(stdout);
	}
	return 0;
}
