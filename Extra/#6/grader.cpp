#include "foo.cc"
#include <bits/stdc++.h>
using namespace std;
ifstream do_cin("/dev/stdin");
ofstream do_cout("/dev/stdout");
unsigned int z = 813699126;
inline unsigned int get()
{
	z ^= z << 7;
	z ^= z >> 23;
	z ^= z << 12;
	return z;
}
inline int rd()
{
	int x = 0;
	for (int i = 1; i <= 9; i++)
		x = x * 10 + get() % 10;
	return x + 1;
}
struct H
{
	int h1, h2, h3;
	void init()
	{
		h1 = h2 = h3 = 0;
	}
	void add(int x)
	{
		h1 = (123456ll * h1 + (998244353 - x)) % 1000000007;
		h2 = (234567ll * h2 + (998244353 - x)) % 1234567891;
		h3 = (345678ll * h3 + (998244353 - x)) % 2147483647;
	}
	void print()
	{
		do_cout << h1 << ' ' << h2 << ' ' << h3 << endl;
	}
};
H output;
void do_clear()
{
	clear();
	output.add(123456789);
}
void do_add(int x, int y)
{
	add(x, y);
}
void do_query(int x, int y)
{
	int res = query(x, y);
	if (res < 0 || res > 10000000) res = -1;
	output.add(res);
}
int main()
{
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	int C;
	do_cin >> C >> z;
	output.init();
	switch (C)
	{
		case 1:
		{
			do_clear();
			do_query(1, 1);
			do_query(1, 2);
			do_query(2, 1);
			do_query(2, 2);
			do_add(1, 1);
			do_query(1, 1);
			do_query(1, 2);
			do_query(2, 1);
			do_query(2, 2);
			do_add(2, 2);
			do_query(1, 1);
			do_query(1, 2);
			do_query(2, 1);
			do_query(2, 2);
			do_clear();
			do_query(1, 1);
			do_query(1, 2);
			do_query(2, 1);
			do_query(2, 2);
			do_add(2, 2);
			do_query(1, 1);
			do_query(1, 2);
			do_query(2, 1);
			do_query(2, 2);
			do_add(1, 1);
			do_query(1, 1);
			do_query(1, 2);
			do_query(2, 1);
			do_query(2, 2);
			break;
		}
		case 2:
		{
			do_clear();
			do_query(1, 2);
			do_query(2, 2);
			do_query(3, 3);
			do_add(1, 3);
			do_query(1, 2);
			do_query(2, 2);
			do_query(3, 3);
			do_add(3, 3);
			do_query(1, 2);
			do_query(2, 2);
			do_query(3, 3);
			do_clear();
			do_query(1, 2);
			do_query(2, 2);
			do_query(3, 3);
			do_add(3, 3);
			do_query(1, 2);
			do_query(2, 2);
			do_query(3, 3);
			do_add(1, 3);
			do_query(1, 2);
			do_query(2, 2);
			do_query(3, 3);
			break;
		}
		case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
		{
			int points[9] = {11, 12, 13, 21, 22, 23, 31, 32, 33};
			swap(points[0], points[C - 3]);
			sort(points + 1, points + 9);
			do
			{
				do_clear();
				for (int i = 0; i <= 8; i++)
				{
					for (int l = 1; l <= 27; l++)
						do_add(points[i] / 10, points[i] % 10);
					for (int l = 1; l <= 3; l++)
						for (int j = 1; j <= 3; j++)
							for (int k = 1; k <= 3; k++)
								do_query(j, k);
				}
			}
			while (next_permutation(points + 1, points + 9));
			break;
		}
		case 12: case 13: case 14: case 15: case 16:
		{
			unsigned int x[10], y[10];
			for (int t = 1; t <= 100000; t++)
			{
				do_clear();
				for (int i = 0; i <= 9; i++)
				{
					x[i] = rd();
					y[i] = rd();
				}
				for (int i = 1; i <= 100; i++)
				{
					do_add(x[get() % 10], y[get() % 10]);
					do_query(x[get() % 10], y[get() % 10]);
				}
			}
			break;
		}
		case 17:
		{
			do_clear();
			for (int i = 1; i <= 2000000; i++)
				do_add(1000000000, 1000000000);
			int xx = rd();
			for (int i = 1; i <= 2000000; i++)
				do_add(xx, 1000000000);
			int yy = rd();
			for (int i = 1; i <= 2000000; i++)
				do_add(1000000000, yy);
			for (int i = 1; i <= 2000000; i++)
			{
				int x = rd();
				do_add(x, 1000000000);
			}
			for (int i = 1; i <= 2000000; i++)
			{
				int y = rd();
				do_add(1000000000, y);
			}
			for (int i = 1; i <= 2000000; i++)
				do_query(1000000000, 1000000000);
			for (int i = 1; i <= 2000000; i++)
				do_query(xx, 1000000000);
			for (int i = 1; i <= 2000000; i++)
				do_query(1000000000, yy);
			for (int i = 1; i <= 2000000; i++)
			{
				int x = rd();
				do_query(x, 1000000000);
			}
			for (int i = 1; i <= 2000000; i++)
			{
				int y = rd();
				do_query(1000000000, y);
			}
			break;
		}
		case 18:
		{
			do_clear();
			for (int i = 1; i <= 2000000; i++)
			{
				int x = rd();
				do_add(x, 1000000000);
			}
			for (int i = 1; i <= 2000000; i++)
			{
				int y = rd();
				do_add(1000000000, y);
			}
			for (int i = 1; i <= 2000000; i++)
			{
				int x = rd();
				do_query(x, 1000000000);
			}
			for (int i = 1; i <= 2000000; i++)
			{
				int y = rd();
				do_query(1000000000, y);
			}
			int xx = rd();
			for (int i = 1; i <= 2000000; i++)
				do_add(xx, 1000000000);
			int yy = rd();
			for (int i = 1; i <= 2000000; i++)
				do_add(1000000000, yy);
			for (int i = 1; i <= 2000000; i++)
				do_query(xx, 1000000000);
			for (int i = 1; i <= 2000000; i++)
				do_query(1000000000, yy);
			for (int i = 1; i <= 2000000; i++)
				do_add(1000000000, 1000000000);
			for (int i = 1; i <= 2000000; i++)
				do_query(1000000000, 1000000000);
			break;
		}
		case 19:
		{
			do_clear();
			for (int i = 1; i <= 1999999; i++)
				do_add(1000000000, 1000000000);
			int xx = rd();
			for (int i = 1; i <= 2000000; i++)
				do_add(xx, 1000000000);
			int yy = rd();
			for (int i = 1; i <= 2000000; i++)
				do_add(1000000000, yy);
			do_add(666666666, 666666666);
			for (int i = 1; i <= 2000000; i++)
			{
				int x = rd();
				do_add(x, 1000000000);
			}
			for (int i = 1; i <= 2000000; i++)
			{
				int y = rd();
				do_add(1000000000, y);
			}
			for (int i = 1; i <= 5000000; i++)
				do_query(1000000000, 1000000000);
			for (int i = 1; i <= 1000000; i++)
				do_query(xx, 1000000000);
			for (int i = 1; i <= 1000000; i++)
				do_query(1000000000, yy);
			for (int i = 1; i <= 1000000; i++)
			{
				int x = rd();
				do_query(x, 1000000000);
			}
			for (int i = 1; i <= 1000000; i++)
			{
				int y = rd();
				do_query(1000000000, y);
			}
			for (int i = 1; i <= 1000000; i++)
			{
				int x = rd();
				int y = rd();
				do_query(x, y);
			}
			break;
		}
		case 20:
		{
			do_clear();
			for (int i = 1; i <= 1000000; i++)
			{
				int x = rd();
				do_add(x, 1000000000);
				int y = rd();
				do_add(1000000000, y);
				x = rd();
				do_add(x, 1000000000);
				y = rd();
				do_add(1000000000, y);
				x = rd();
				do_query(x, 1000000000);
				y = rd();
				do_query(1000000000, y);
				do_query(1000000000, 1000000000);
			}
			for (int i = 1; i <= 1999999; i++)
				do_add(1000000000, 1000000000);
			for (int i = 1; i <= 1000000; i++)
				do_query(1000000000, 1000000000);
			do_add(666666666, 666666666);
			for (int i = 1; i <= 1000000; i++)
				do_query(1000000000, 1000000000);
			int xx = rd();
			for (int i = 1; i <= 2000000; i++)
				do_add(xx, 1000000000);
			for (int i = 1; i <= 1000000; i++)
			{
				do_query(xx, 1000000000);
				do_query(1000000000, 1000000000);
			}
			int yy = rd();
			for (int i = 1; i <= 2000000; i++)
				do_add(1000000000, yy);
			for (int i = 1; i <= 1000000; i++)
			{
				do_query(1000000000, yy);
				do_query(1000000000, 1000000000);
			}
			for (int i = 1; i <= 1000000; i++)
			{
				int x = rd();
				int y = rd();
				do_query(x, y);
			}
			break;
		}
	}
	output.print();
	return 0;
}
