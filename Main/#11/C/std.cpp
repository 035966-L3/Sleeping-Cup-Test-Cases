#include <bits/stdc++.h>
using namespace std;
const int M = 100 + 12, V = 1023, T = 1023 + 12;
bool dp[M][T];
int main()
{
	freopen("knapsack.in", "r", stdin);
	freopen("knapsack.out", "w", stdout);
	dp[0][0] = true;
	int n, m;
	cin >> n >> m;
	while (n--)
	{
		int w, l;
		cin >> w >> l;
		for (int i = m; i >= w; i--)
			for (int j = 0; j <= V; j++)
				dp[i][j] |= dp[i - w][j ^ l];
	}
	for (int i = V; i >= 0; i--)
		for (int j = m; j >= 0; j--)
			if (dp[j][i])
			{
				cout << i << endl;
				return 0;
			}
	return 0;
}
