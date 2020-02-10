class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		if (nums.empty()) return 0;
		map<int, int> mp;
		for (int val : nums) mp[val]++;

		int n = mp.size();
		vector<pair<int, int>> val;
		vector<int> f(n);
		for (const auto &p : mp) val.push_back({ p.first, p.first * p.second });

		f[0] = val[0].second;
		for (int i = 1; i < n; i++) {
			f[i] = f[i - 1];
			if (i > 1) f[i] = max(f[i], f[i - 2] + val[i].second);
			if (val[i].first - val[i - 1].first > 1) f[i] = max(f[i], f[i - 1] + val[i].second);
			else f[i] = max(f[i], val[i].second);
		}
		return f[n - 1];
	}
};