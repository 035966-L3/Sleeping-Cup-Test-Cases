#include <bits/stdc++.h>
using namespace std;
struct NodeState {
	int index;
	int length;
	int signal;
};
int cs(int type, int signal) {
	if (type == 0) return 0;
	if (type == 2) return 15;
	if (type == 3) return signal - 1;
	if (type >= 4 && type <= 7) {
		int boost = 0;
		if (type == 4) boost = 0;
		else if (type == 5) boost = 1;
		else if (type == 6) boost = 2;
		else if (type == 7) boost = 4;
		return (signal + boost) - 1;
	}
	return signal;
}
int dfs(const vector<int>& tree) {
	if (tree.empty() || tree[0] != 1) {
		return 0;
	}
	int max_l = 0;
	stack<NodeState> stk;
	stk.push({0, 0, 15});
	while (!stk.empty()) {
		NodeState c = stk.top();
		stk.pop();
		if (c.index >= tree.size() || c.signal <= 0 || tree[c.index] == 0) {
			continue;
		}
		int new_s = cs(tree[c.index], c.signal);
		int new_l = c.length + 1;
		if (new_l > max_l) {
			max_l = new_l;
		}
		if (new_s > 0) {
			stk.push({2 * c.index + 2, new_l, new_s});
			stk.push({2 * c.index + 1, new_l, new_s});
		}
	}

	return max_l;
}

int main() {
	freopen("traversal.in", "r", stdin);
	freopen("traversal.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> tree(n);
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}

	int result = dfs(tree);
	cout << result << endl;
	return 0;
}
