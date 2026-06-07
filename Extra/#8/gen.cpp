#include <bits/stdc++.h>
using namespace std;
char s[10];
int main()
{
	int k = 0;
	for (long long i = 1; i <= 1000000000000ll; i *= 10)
	{
		k++;
		sprintf(s, "%d.in", k);
		freopen(s, "wb", stdout);
		cout << i << endl;
		fclose(stdout);
	}
	return 0;
}
