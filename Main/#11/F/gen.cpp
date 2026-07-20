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
int main()
{
	freopen("27.in", "wb", stdout);
	for (int i = 1; i <= 100000; i++)
		printf("a");
	puts("");
	fclose(stdout);
	freopen("28.in", "wb", stdout);
	for (int i = 1; i <= 50000; i++)
		printf("ab");
	puts("");
	fclose(stdout);
	freopen("29.in", "wb", stdout);
	for (int i = 1; i <= 33333; i++)
		printf("abc");
	puts("a");
	fclose(stdout);
	freopen("30.in", "wb", stdout);
	for (int i = 1; i <= 3846; i++)
		printf("abcdefghijklmnopqrstuvwxyz");
	puts("abcd");
	fclose(stdout);
	for (int k = 31; k <= 35; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		string b[40];
		for (int i = 0; i <= 19; i++)
		{
			int l = get() % 6 + 7;
			b[i] = "";
			while (l--) b[i] += (char) ('a' + get() % 26);
		}
		for (int i = 20; i <= 39; i++)
		{
			b[i] = b[i - 20];
			reverse(b[i].begin(), b[i].end());
		}
		for (int i = 1; i <= 10000; i++)
			printf("%s", b[get() % 40].c_str());
		puts("");
		fclose(stdout);
	}
	for (int k = 36; k <= 40; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		int n = 90000 + get() % 10000, l = get() % n, r = get() % n;
		while (r - l <= 40000)
		{
			l = get() % n + 1;
			r = get() % n + 1;
		}
		int p = r - l + 1, t = get() % (p / 2) + 1;
		while (t <= 10000 || p - 2 * t <= 10000) t = get() % (p / 2) + 1;
		string w = "";
		for (int i = 0; i <= n - 1; i++)
			w += (char) ('a' + get() % 26);
		for (int i = l, j = r, o = 1; o <= t; i++, j--, o++)
			w[j] = w[i];
		printf("%s\n", w.c_str());
		fclose(stdout);
	}
	for (int k = 41; k <= 45; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		int n = 90000 + get() % 10000;
		while (n--) printf("%c", 'a' + get() % 2);
		puts("");
		fclose(stdout);
	}
	for (int k = 46; k <= 50; k++)
	{
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		int n = 90000 + get() % 10000;
		while (n--) printf("%c", 'a' + get() % 26);
		puts("");
		fclose(stdout);
	}
	return 0;
}
