class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int n = nums.size();
		vector<vector<pair<int, int>>> f(n, vector<pair<int, int>>(n, { 0, 0 }));
		for (int i = 0; i < n; i++) f[i][i] = { nums[i], 0 };
		for (int left = 2; left <= n; left++) {
			for (int l = 0; l + left - 1 < n; l++) {
				int r = l + left - 1;
				auto resA = make_pair(f[l + 1][r].second + nums[l], f[l + 1][r].first);
				auto resB = make_pair(f[l][r - 1].second + nums[r], f[l][r - 1].first);
				if (resA.first > resB.first) f[l][r] = resA;
				else if (resA.first == resB.first && resA.second >= resB.second)  f[l][r] = resA;
				else f[l][r] = resB;
			}
		}
		return f[0][n - 1].first >= f[0][n - 1].second;
	}
};