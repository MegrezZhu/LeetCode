class Solution {
public:
	int minFallingPathSum(const vector<vector<int>>& arr) {
		int n = arr.size();
		vector<vector<int>> f(n, vector<int>(n));

		f[0] = arr[0];
		for (int i = 1; i < n; i++) {
			int min1 = 1e9, minn1 = -1, min2 = 1e9, minn2 = -1;
			for (int j = 0; j < n; j++) {
				if (f[i - 1][j] <= min1) {
					min2 = min1;
					minn2 = minn1;
					min1 = f[i - 1][j];
					minn1 = j;
				}
				else if (f[i - 1][j] < min2) {
					min2 = f[i - 1][j];
					minn2 = j;
				}
			}
			for (int j = 0; j < n; j++) {
				if (minn1 != j) {
					f[i][j] = arr[i][j] + f[i - 1][minn1];
				}
				else {
					f[i][j] = arr[i][j] + f[i - 1][minn2];
				}
			}
		}
		int ans = 1e9;
		for (int i = 0; i < n; i++) {
			ans = min(ans, f[n - 1][i]);
		}
		return ans;
	}
};