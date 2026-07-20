#include <bits/stdc++.h>
using namespace std;
namespace Sorting
{
	const int N = 1000 + 12;
	int p[N];
	int remain = 50000;
	void init()
	{
		for (int i = 1; i <= 1000; i++)
			cin >> p[i];
	}
	int operate(int l, int r)
	{
		if (!p[1]) init();
		if (l < 1 || l > 1000 || r < 1 || r > 1000 || l >= r)
		{
			puts("Invalid query!");
			exit(0);
		}
		int between = 0;
		for (int i = l + 1; i <= r - 1; i++)
			if ((p[i] - p[l]) * (p[i] - p[r]) < 0) between++;
		int coins = 2 * between + 2;
		if (p[l] > p[r]) coins = 1;
		remain -= coins;
		if (remain < 0)
		{
			puts("Out of coins!");
			exit(0);
		}
		swap(p[l], p[r]);
		return coins;
	}
	void confirm()
	{
		if (!p[1]) init();
		for (int i = 1; i <= 1000; i++)
			if (p[i] != i)
			{
				puts("Wrong Answer!");
				exit(0);
			}
		printf("Accepted! (%d coins remaining)\n", remain);
		exit(0);
	}
}
using Sorting::operate;
using Sorting::confirm;
