class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int n = dungeon.size(), m = dungeon.front().size();
		vector<vector<int>> res;
		res.resize(n + 1);
		for (auto it = res.begin(); it != res.end(); it++) it->resize(m + 1, 1e9);
		res[n - 1][m - 1] = max(-dungeon[n - 1][m - 1], 0);
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				if (i == n - 1 && j == m - 1) continue;
				res[i][j] = -dungeon[i][j] + min(res[i][j + 1], res[i + 1][j]);
				res[i][j] = max(res[i][j], 0);
			}
		}
		return res[0][0] + 1;
	}
};