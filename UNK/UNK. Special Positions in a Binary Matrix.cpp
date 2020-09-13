class Solution {
public:
	int numSpecial(const vector<vector<int>>& mat) {
		int n = mat.size(), m = mat.front().size();
		vector<int> rows(n, 0), cols(m, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 0) continue;
				rows[i]++;
				cols[j]++;
			}
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
					count++;
				}
			}
		}
		return count;
	}
};