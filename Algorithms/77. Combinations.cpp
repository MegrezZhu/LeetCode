class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		if (k > n) return {};
		if (k == 0) return { {} };
        if (k == 1) {
            vector<vector<int>> res(n, vector<int>(1));
            for (int i = 0; i < n; i++) res[i][0] = i + 1;
            return res;
        }
		if (n == k) {
			vector<vector<int>> res({ vector<int>(n) });
			for (int i = 0; i < n; i++) res[0][i] = i + 1;
			return res;
		}
		auto res = combine(n - 1, k);
		auto res1 = combine(n - 1, k - 1);
		for (auto& v : res1) {
			v.push_back(n);
			res.push_back(move(v));
		}
		return res;
	}
};