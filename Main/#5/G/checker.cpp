#include <bits/stdc++.h>
#include "testlib.h"
#define int long long
#define ans ansans
using namespace std;
const int N = 2e4 + 12;
struct P
{
	int x, y, z;
};
const P E = (P){0, 0, 0};
P operator-(P x, P y)
{
	return (P){x.x - y.x, x.y - y.y, x.z - y.z};
}
bool operator==(P x, P y)
{
	__int128 rt1 = 0, rt2 = 0;
	if (x.x == 0 && y.x != 0) return false;
	if (x.x != 0 && y.x == 0) return false;
	if (x.y == 0 && y.y != 0) return false;
	if (x.y != 0 && y.y == 0) return false;
	if (x.z == 0 && y.z != 0) return false;
	if (x.z != 0 && y.z == 0) return false;
	if (x.x != 0) rt1 = x.x, rt2 = y.x;
	if (x.y != 0) rt1 = x.y, rt2 = y.y;
	if (x.z != 0) rt1 = x.z, rt2 = y.z;
	if (x.x * rt2 != y.x * rt1) return false;
	if (x.y * rt2 != y.y * rt1) return false;
	if (x.z * rt2 != y.z * rt1) return false;
	return true;
}
bool operator!=(P x, P y)
{
	return !(x == y);
}
bool straight(P x, P y)
{
	return (__int128) x.x * y.x + (__int128) x.y * y.y + (__int128) x.z * y.z == 0;
}
P in[N], fir[N], sec[N];
P normal(P x, P y, P z)
{
	P a = x - y, b = x - z;
	int nx = a.y * b.z - a.z * b.y;
	int ny = a.z * b.x - a.x * b.z;
	int nz = a.x * b.y - a.y * b.x;
	return (P){nx, ny, nz};
}
bool operator<(P x, P y)
{
	if (x.x != y.x) return x.x < y.x;
	if (x.y != y.y) return x.y < y.y;
	return x.z < y.z;
}
signed main(signed argc, char** argv)
{
	registerTestlibCmd(argc, argv);
	int T = inf.readInt();
	for (int t = 1; t <= T; t++)
	{
		setTestCase(t);
		int n = inf.readInt();
		for (int i = 1; i <= 2 * n; i++)
			in[i] = (P){inf.readInt(), inf.readInt(), inf.readInt()};
		string ans = ' ' + ouf.readLine();
		if ((int) ans.size() != 2 * n + 1) quitf(_wa, "Invalid output!");
		int p1 = 0, p2 = 0;
		for (int i = 1; i <= 2 * n; i++)
		{
			if (ans[i] != '0' && ans[i] != '1') quitf(_wa, "Invalid output!");
			if (ans[i] == '1') p1++, fir[p1] = in[i];
			else p2++, sec[p2] = in[i];
			if (p1 > n || p2 > n) quitf(_wa, "Invalid output!");
		}
		if (n == 1) continue;
		P l1 = fir[2] - fir[1], l2 = sec[2] - sec[1], n1 = E, n2 = E;
		for (int i = 3; i <= n; i++)
		{
			if (fir[i] - fir[1] != l1)
			{
				if (n1 == E) n1 = normal(fir[1], fir[2], fir[i]);
				if (n1 != normal(fir[1], fir[2], fir[i])) quitf(_wa, "Wrong construction!");
			}
			if (sec[i] - sec[1] != l2)
			{
				if (n2 == E) n2 = normal(sec[1], sec[2], sec[i]);
				if (n2 != normal(sec[1], sec[2], sec[i])) quitf(_wa, "Wrong construction!");
			}
		}
		if (n1 != E && n2 != E)
		{
			if (n1 != n2) quitf(_wa, "Wrong construction!");
			if (sec[1] - fir[1] == l1) quitf(_wa, "Wrong construction!");
			if (normal(sec[1], fir[1], fir[2]) == n1) quitf(_wa, "Wrong construction!");
		}
		if (n1 == E && n2 != E)
		{
			if (!straight(l1, n2)) quitf(_wa, "Wrong construction!");
			if (sec[1] - fir[1] == l2) quitf(_wa, "Wrong construction!");
			if (normal(fir[1], sec[1], sec[2]) == n2) quitf(_wa, "Wrong construction!");
		}
		if (n1 != E && n2 == E)
		{
			if (!straight(l2, n1)) quitf(_wa, "Wrong construction!");
			if (sec[1] - fir[1] == l1) quitf(_wa, "Wrong construction!");
			if (normal(sec[1], fir[1], fir[2]) == n1) quitf(_wa, "Wrong construction!");
		}
		if (n1 == E && n2 == E)
		{
			if (sec[1] - fir[1] == l1) quitf(_wa, "Wrong construction!");
			if (sec[2] - fir[1] == l1) quitf(_wa, "Wrong construction!");
			if (l1 != l2 && normal(fir[1], fir[2], sec[1]) == normal(fir[1], fir[2], sec[2])) quitf(_wa, "Wrong construction!");
		}
	}
	quitf(_ok, "Accepted!");
	return 0;
}
