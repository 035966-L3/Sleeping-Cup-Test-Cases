#include <bits/stdc++.h>
using namespace std;
bool o = false;
int f(int x)
{
	if (o) return 0;
	cout << x << endl;
	int y;
	cin >> y;
	if (y == 10000) o = true;
	return y;
}
int main()
{
	int T = 250;
	while (T--)
	{
		o = false;
		int n = 10000, l = 1, r = n;
		while (l < r)
		{
			int p = l + (r - l) / 3, q = r - (r - l) / 3, x = f(p), y = f(q);
			if (o) break;
			if (x < y) l = p + 1;
			if (x > y) r = q - 1;
		}
	}
	return 0;
}
