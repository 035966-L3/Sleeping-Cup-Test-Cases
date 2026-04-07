#include<bits/stdc++.h>
using namespace std;
int n = 600, m = 600;
int main(){
	srand(time(NULL));
	for (int i = 2; i <= 25; i++) {
		freopen((to_string(i) + ".in").c_str(), "w", stdout);
		cout << rand() % 100 + 501 << " " << m << endl;
		for (int i = 1; i <= m; i++) {
			cout << rand() % 10 + 1 << " " << rand() % 10 + 1 << endl;
		}
		fclose(stdout);
	}
	return 0;
}
