#include<bits/stdc++.h>
using namespace std;
int m,n,w[100005],c[100005];
int f[605][605];
int main() {
	freopen("entries.in", "r", stdin);
	freopen("entries.out", "w", stdout);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j >= w[i]) {
				f[i][j] = max(f[i - 1][j],f[i - 1][j - w[i]] + c[i]);
			} else {
				f[i][j] = f[i-1][j];
			}
		}
	}
	cout <<  f[n][m] << endl;
	return 0;
}
