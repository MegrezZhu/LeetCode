class NumMatrix {
	int n, m;
	vector<vector<int>> sum;
public:
	NumMatrix(vector<vector<int>>& matrix) : n(matrix.size()),
											 m(n > 0 ? matrix.front().size() : 0),
											 sum(n + 1, vector<int>(m + 1, 0)) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				sum[i][j] = sum[i][j - 1] + matrix[i - 1][j - 1];
			}
		}
		for (int j = 1; j <= m; j++) {
			for (int i = 1; i <= n; i++) {
				sum[i][j] = sum[i - 1][j] + sum[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */