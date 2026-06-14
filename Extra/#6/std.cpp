#include <bits/stdc++.h>
using namespace std;
int n = 0;
struct Point
{
	int x, y, i;
};
Point p[7];
void clear()
{
	n = 0;
	memset(p, 0, sizeof p);
}
void add(int x, int y)
{
	n++;
	if (!p[0].i)
	{
		p[0] = (Point) {x, y, n};
		return;
	}
	if (x == p[0].x && y != p[0].y && !p[1].i) p[1] = (Point) {x, y, n};
	if (x != p[0].x && y == p[0].y && !p[2].i) p[2] = (Point) {x, y, n};
	if (x != p[0].x && y != p[0].y)
	{
		if (!p[3].i)
		{
			p[3] = (Point) {x, y, n};
			return;
		}
		if (x == p[3].x && y != p[3].y && !p[4].i) p[4] = (Point) {x, y, n};
		if (x != p[3].x && y == p[3].y && !p[5].i) p[5] = (Point) {x, y, n};
		if (x != p[3].x && y != p[3].y && !p[6].i) p[6] = (Point) {x, y, n};
	}
}
int query(int x, int y)
{
	int ans = n + 1;
	for (int i = 0; i <= 6; i++)
		if (x != p[i].x && y != p[i].y && p[i].i) ans = min(ans, p[i].i);
	if (ans == n + 1) ans = 0;
	return ans;
}
