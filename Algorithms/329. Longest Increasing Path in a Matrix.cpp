class Solution {
    static int dx[4];
    static int dy[4];

	int dp(const vector<vector<int>>& matrix, vector<vector<int>>& result, int x, int y) {
		if (result[x][y] > 0) return result[x][y];

		int n = matrix.size(), m = matrix.front().size();
		result[x][y] = 1;
		for (int dir = 0; dir < 4; dir++) {
			int tx = x + dx[dir], ty = y + dy[dir];
			if (tx < 0 || tx >= n || ty < 0 || ty >= m || matrix[tx][ty] <= matrix[x][y]) continue;
			result[x][y] = max(result[x][y], dp(matrix, result, tx, ty) + 1);
		}

		return result[x][y];
	}
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty()) return 0;
        
		int n = matrix.size(), m = matrix.front().size();
		vector<vector<int>> results(n, vector<int>(m, -1));
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) ans = max(ans, dp(matrix, results, i, j));
		}

		return ans;
	}
};

int Solution::dx[4] = { 0, 1, 0, -1 };
int Solution::dy[4] = { 1, 0, -1, 0 };