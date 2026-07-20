#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 12;
int z[N];
int main()
{
	freopen("rating.in", "r", stdin);
	freopen("rating.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> z[i];
	for (int i = n; i >= 1; i--)
		z[i - 1] += z[i] / 2;
	cout << max(z[0], 1) << endl;
	return 0;
}
