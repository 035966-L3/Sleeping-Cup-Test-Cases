#include <bits/stdc++.h>
using namespace std;
const string names[2] =
{
	"Sleeping Iguana",
	"Sleeping Alligator"
};
const int results[3][6] =
{
	{1, 0, 0, 1, 1, 1},
	{0, 1, 0, 1, 0, 0},
	{1, 0, 1, 0, 0, 0}
};
int main()
{
	freopen("savings.in", "r", stdin);
	freopen("savings.out", "w", stdout);
	int T, n, m;
	cin >> T;
	while (cin >> n >> m) cout << names[results[n % 3][m % 6]] << endl;
	return 0;
}
