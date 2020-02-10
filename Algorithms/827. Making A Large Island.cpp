class Solution {
public:
	int largestIsland(vector<vector<int>>& grid) {
		if (grid.empty()) return 0;
		int n = grid.size(), m = grid.front().size();
		vector<int> f(n * m, -1);

		static const int dx[4] = { 0, 1, 0, -1 };
		static const int dy[4] = { 1, 0, -1, 0 };

		int ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 0) continue;
				for (int t = 0; t < 4; t++) {
					int tx = i + dx[t], ty = j + dy[t];
					if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == 1) {
						_union(f, i * n + j, tx * n + ty);
					}
				}
				ans = max(ans, size(f, i * n + j));
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 0) {
					unordered_set<int> group;
					int _ans = 1;
					for (int t = 0; t < 4; t++) {
						int tx = i + dx[t], ty = j + dy[t];
						if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == 1) {
							int island = find(f, tx * n + ty);
							if (group.find(island) == group.end()) {
								_ans += size(f, tx * n + ty);
								group.insert(island);
							}
						}
					}
					ans = max(ans, _ans);
				}
			}
		}

		return ans;
	}
	int find(vector<int> &f, int id) {
		int p = id;
		while (f[p] >= 0) p = f[p];
		int p1 = id;
		while (p1 != p) {
			int tmp = f[p1];
			f[p1] = p;
			p1 = tmp;
		}
		return p;
	}
	void _union(vector<int> &f, int p1, int p2) {
		int fa1 = find(f, p1), fa2 = find(f, p2);
		if (fa1 != fa2) {
			int count = -(f[fa1] + f[fa2]);
			f[fa2] = fa1;
			f[fa1] = -count;
		}
	}
	int size(vector<int> &f, int p) {
		return -f[find(f, p)];
	}
};