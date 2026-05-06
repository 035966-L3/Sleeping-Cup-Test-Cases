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
int counter = 0;
char output[10000012];
char* pointer = output;
bool flip[100012];
void flush()
{
	counter = 0;
	pointer = output;
	memset(output, 0, sizeof output);
}
void element()
{
	counter++;
	pointer += sprintf(pointer, "a[%d]", counter);
}
void divide(int n, int s2)
{
	if (n == 0)
	{
		element();
		return;
	}
	int left = 0;
	switch (s2)
	{
		case 1:
		{
			left = rd(n) - 1;
			break;
		}
		case 2:
		{
			left = n / 2;
			break;
		}
		case 3:
		{
			left = (rd(2) - 1) * (n - 1);
			break;
		}
		case 4:
		{
			left = 0;
			break;
		}
	}
	pointer += sprintf(pointer, "min(");
	divide(left, s2);
	pointer += sprintf(pointer, ",");
	divide(n - 1 - left, s2);
	pointer += sprintf(pointer, ")");
}
void fill(int n, int s1)
{
	memset(flip, 0, sizeof flip);
	switch (s1)
	{
		case 1:
		{
			for (int i = 1; i <= n; i++)
				flip[i] = rd(2) - 1;
			break;
		}
		case 2:
		{
			for (int i = 1; i <= n; i++)
				flip[i] = rd(1000) - 1;
			for (int i = 1; i <= n; i++)
				flip[i] = !flip[i];
			for (int i = 1; i <= n; i++)
				flip[i] ^= flip[i - 1];
			break;
		}
		case 3:
		{
			for (int i = 1; i <= n; i++)
				flip[i] = rd(1000) - 1;
			break;
		}
		case 4:
		{
			int m = strlen(output);
			int layer = 0;
			int id = 0;
			for (int i = 0; i < m; i++)
			{
				if (output[i] == ')') layer--;
				if (output[i] == '(')
				{
					layer++;
					id++;
					flip[id] = layer % 2;
				}
			}
			break;
		}
	}
	int m = strlen(output);
	int id = 0;
	for (int i = 0; i < m; i++)
		if (output[i] == '(')
		{
			id++;
			if (flip[id])
			{
				output[i - 2] = 'a';
				output[i - 1] = 'x';
			}
		}
}
void generate(int s1, int s2, int s3)
{
	flush();
	int n = 99999;
	if (!s3) n = 89999 + rd(10000);
	divide(n, s2);
	fill(n, s1);
	printf("%s\n", output);
}
int main()
{
	string tc;
	int T, s1, s2, s3;
	while (cin >> tc >> T)
	{
		tc += ".in";
		freopen(tc.c_str(), "wb", stdout);
		printf("%d\n", T);
		while (T--)
		{
			cin >> s1 >> s2 >> s3;
			generate(s1, s2, s3);
		}
		fclose(stdout);
	}
	return 0;
}
