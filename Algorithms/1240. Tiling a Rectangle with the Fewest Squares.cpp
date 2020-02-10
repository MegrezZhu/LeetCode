class Solution {
	vector<vector<int>> f;
public:
	int tilingRectangle(int n, int m) {
		f = vector<vector<int>>(max(n, m) + 1, vector<int>(max(n, m) + 1, -1));
		return compute(n, m);
	}
	int compute(int n, int m) {
		if (n > m) return compute(m, n);
		if (n == m) return 1;
		if (f[n][m] != -1) return f[n][m];
		int ans = 1e9;

		for (int i = 1; i < n; i++) {
			ans = min(ans, compute(i, m) + compute(n - i, m));
		}
		for (int i = 1; i < m; i++) {
			ans = min(ans, compute(n, i) + compute(n, m - i));
		}
		for (int x = 2; x < n; x++) {
			for (int y = 2; y < m; y++) {
				for (int x1 = x; x1 < n; x1++) {
					for (int y1 = y; y1 < m; y1++) {
						int t = compute(x1 - x + 1, y1 - y + 1);
						t += compute(x - 1, y1);
						t += compute(x1, m - y1);
						t += compute(n - x1, m - y + 1);
						t += compute(n - x + 1, y - 1);
						ans = min(ans, t);
					}
				}
			}
		}

		f[n][m] = ans;
		return ans;
	}
};