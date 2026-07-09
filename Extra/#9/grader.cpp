#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
const int N = 1e4 + 12;
int a[N];
int main(int argc, char* argv[])
{
	registerInteraction(argc, argv);
	int T = 250, u = 0, v = 0;
	for (int _ = 1; _ <= T; _++)
	{
		setTestCase(_);
		int n = 10000;
		for (int i = 1; i <= n; i++)
			a[i] = inf.readInt();
		bool o = false;
		int q = 100;
		for (int i = 1; i <= q; i++)
		{
			int k = ouf.readInt(1, n);
			int b = a[k];
			cout << b << endl;
			cout.flush();
			if (b == n)
			{
				o = true;
				u += i;
				v = max(v, i);
				break;
			}
		}
		if (!o) quitf(_wa, "Out of queries!");
	}
	quitf(_ok, "Accepted! [%.3f queries on avarage, %d queries maximum]", u * 1.0 / T, v);
}
