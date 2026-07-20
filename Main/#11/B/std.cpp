#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int divs(int a, int b, int p)
{
	if (b % a == 0) return b / a;
	int x = divs(p % a, a - b % a, a);
	return (1ll * x * p + b) / a;
}
int main()
{
	freopen("chaining.in", "r", stdin);
	freopen("chaining.out", "w", stdout);
	long long n, m, k;
	cin >> n >> m >> k;
	cout << divs(2 * n % P, k * (2 * n + m - 1) % P, P) << endl;
	return 0;
}
