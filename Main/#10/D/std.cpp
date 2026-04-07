#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("population.in", "r", stdin);
	freopen("population.out", "w", stdout);
	int m, n;
	long long steps;
	cin >> m >> n >> steps;
	vector<vector<int> > grid(m, vector<int>(n));
	vector<vector<int> > fixed(m, vector<int>(n));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] >= 2) {
				fixed[i][j] = grid[i][j];
			} else {
				fixed[i][j] = 0;
			}
		}
	}
	vector<vector<int> > new_grid(m, vector<int>(n));
	for (long long s = 0; s < steps; ++s) {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (fixed[i][j] >= 2) {
					new_grid[i][j] = fixed[i][j];
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (fixed[i][j] >= 2) {
					continue;
				}
				int live_count = 0;
				for (int di = -1; di <= 1; ++di) {
					for (int dj = -1; dj <= 1; ++dj) {
						if (di == 0 && dj == 0) {
							continue;
						}
						int ni = i + di;
						int nj = j + dj;
						if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
							if (fixed[ni][nj] == 2) {
								live_count++;
							} else if (fixed[ni][nj] == 3) {
								live_count += 2;
							} else if (fixed[ni][nj] == 4) {
								live_count--;
							} else if (grid[ni][nj] == 1) {
								live_count += 1;
							}
						}
					}
				}
				if (grid[i][j] == 1) {
					if (live_count >= 2 && live_count <= 3) {
						new_grid[i][j] = 1;
					} else {
						new_grid[i][j] = 0;
					}
				} else {
					if (live_count == 3) {
						new_grid[i][j] = 1;
					} else {
						new_grid[i][j] = 0;
					}
				}
			}
		}
		grid.swap(new_grid);
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j > 0) {
				cout << " ";
			}
			cout << grid[i][j];
		}
		cout << endl;
	}
	return 0;
}
