#include <bits/stdc++.h>
#include "sorting.h"
using namespace std;
random_device seed;
mt19937 rd;
const int N = 1000 + 12, Real_N = 1000;
int t[N];
void deal(int l, int r)
{
	if (l >= r) return;
	int p = l + rd() % (r - l + 1);
	for (int i = p; i >= l + 1; i--)
		operate(i - 1, i);
	for (int i = l; i <= r - 1; i++)
		t[i] = operate(i, i + 1);
	queue <int> q;
	for (int i = r - 1; i >= l; i--)
	{
		if (t[i] == 2)
			if (!q.empty())
			{
				operate(i, q.front());
				swap(t[i], t[q.front()]);
				q.pop();
			}
		if (t[i] == 1) q.push(i);
	}
	p = r;
	for (int i = l; i <= r - 1; i++)
		if (t[i] == 2)
		{
			operate(i, r);
			p = i;
			break;
		}
	deal(l, p - 1);
	deal(p + 1, r);
}
int main()
{
	rd.seed(seed());
	deal(1, Real_N);
	confirm();
	return 0;
}
