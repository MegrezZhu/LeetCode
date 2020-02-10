class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>> f = triangle;
        
        for (auto &row : f) {
            for (int &v : row) v = 2e9;
        }
        f[0][0] = triangle[0][0];
        
		for (int i = 0; i < triangle.size() - 1; i++) {
			for (int j = 0; j < triangle[i].size(); j++) {
				f[i + 1][j] = min(f[i + 1][j], triangle[i + 1][j] + f[i][j]);
				f[i + 1][j + 1] = min(f[i + 1][j + 1], triangle[i + 1][j + 1] + f[i][j]);
			}
		}
		int ans = 2e9;
		for (int cand : f.back()) ans = min(ans, cand);
		return ans;
	}
};