class Solution {
public:
	bool isMatch(string s, string p) {
		int n = s.length(), m = p.length();
		vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
		f[0][0] = true;
		for (int i = 1; i <= m; i++) {
			switch (p[i - 1]) {
			case '?':
				for (int j = 1; j <= n; j++) {
					f[i][j] = f[i - 1][j - 1];
				}
				break;
			case '*':
				for (int j = 0; j <= n; j++) {
					f[i][j] = f[i - 1][j];
					if (j > 0) {
						f[i][j] = f[i][j] || (f[i][j - 1] || f[i - 1][j - 1]);
					}
				}
				break;
			default:
				for (int j = 1; j <= n; j++) {
					f[i][j] = f[i - 1][j - 1] && (p[i - 1] == s[j - 1]);
				}
			}
		}
		return f[m][n];
	}
};