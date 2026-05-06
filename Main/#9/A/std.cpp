#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("compounds.in", "r", stdin);
	freopen("compounds.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		string S;
		cin >> S;
		int ans = 0;
		stack <int> st;
		st.push('#');
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == '(' && st.top() != S[i - 1]) ans++;
			if (S[i] == '(') st.push(S[i - 1]);
			if (S[i] == ')') st.pop();
		}
		cout << ans << endl;
	}
	return 0;
}
