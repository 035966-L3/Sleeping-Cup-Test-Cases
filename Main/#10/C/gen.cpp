#include <bits/stdc++.h>
using namespace std;
int n, w0;
int main() {
	srand(time(NULL));
	for (int i = 2; i <= 25; i++){
		freopen((to_string(i) + ".in").c_str(), "w", stdout);
		n = pow(2, rand() % 5 + 12) - 1;
		w0 = ((rand() + 1) * (rand() + 1)) % n + 1;
		cout << n << endl;
		for(int i = 1; i <= n; i++){
			if (i == w0) {
				cout << 0 << " ";
				continue;
			}
			if (i == 1) {
				cout << 1 << " ";
				continue;
			}
			cout << rand() % 6 + 2 << " ";
		}
		cout << endl;
		fclose(stdout);
	}
	return 0;
}
