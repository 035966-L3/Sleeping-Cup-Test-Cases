#include <bits/stdc++.h>
using namespace std;
namespace R11E
{
	const int N = 1000 + 12;
	int p[N], a[N], b[N];
	int remain1 = 200000, remain2 = 200000;
	void init()
	{
		for (int i = 1; i <= 1000; i++)
			cin >> a[i];
		for (int i = 1; i <= 1000; i++)
			cin >> b[i];
		for (int i = 1; i <= 1000; i++)
			p[i] = 1001 - b[a[i]];
	}
	int operate(int l, int r)
	{
		if (!p[1]) init();
		if (l < 1 || l > 1000 || r < 1 || r > 1000 || l >= r)
		{
			puts("17268b458a0424dbb7b221a4e5da396d");
			exit(0);
		}
		int between = 0;
		for (int i = l + 1; i <= r - 1; i++)
			if ((p[i] - p[l]) * (p[i] - p[r]) < 0) between++;
		int coins = 2 * between + 2;
		if (p[l] < p[r]) coins = 1;
		if (remain1 < 100000 || remain1 > 200000 || remain1 % 2 || remain1 != remain2)
		{
			puts("42636dc1fc0045cc1ed9ecd136047843");
			exit(0);
		}
		remain1 -= 2 * coins;
		remain2 -= 2 * coins;
		if (remain1 < 100000)
		{
			puts("42636dc1fc0045cc1ed9ecd136047843");
			exit(0);
		}
		swap(p[l], p[r]);
		return coins;
	}
	void confirm()
	{
		if (!p[1]) init();
		if (remain1 < 100000 || remain1 > 200000 || remain1 % 2 || remain1 != remain2)
		{
			puts("42636dc1fc0045cc1ed9ecd136047843");
			exit(0);
		}
		for (int i = 1; i <= 1000; i++)
			if (p[i] != 1001 - i)
			{
				puts("e16ddd3f7430c647bab7633f20b5ae36");
				exit(0);
			}
		printf("be01588eed765809c04c16e75936%04x\n", (remain1 - 100000) / 2);
		exit(0);
	}
}
using R11E::operate;
using R11E::confirm;
