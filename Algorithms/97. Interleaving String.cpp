class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()) return false;
		vector<vector<bool>> dp;
		dp.resize(s1.size() + 1);
		for (auto it = dp.begin(); it != dp.end(); it++) it->resize(s2.size() + 1, false);
		dp[0][0] = true;

		list<pair<int, int>> li = { {0, 0} };
		while (!li.empty()) {
			auto p = li.front();
			li.pop_front();
			dp[p.first][p.second] = true;
			if (p.first + p.second + 1 > s3.size()) continue;
			char next = s3[p.first + p.second];
			if (p.first < s1.size() && s1[p.first] == next) {
				if (!dp[p.first + 1][p.second]) {
					dp[p.first + 1][p.second] = true;
					li.push_back({ p.first + 1, p.second });
				}
			}
			if (p.second < s2.size() && s2[p.second] == next) {
				if (!dp[p.first][p.second + 1]) {
					dp[p.first][p.second + 1] = true;
					li.push_back({ p.first, p.second + 1 });
				}
			}
		}

		return dp[s1.size()][s2.size()];
	}
};