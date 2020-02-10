class Solution {
public:
	int findMaxLength(vector<int> &nums) {
		int n = nums.size();
		int count = 0;
		map<int, pair<int, int>> mp;
		for (int i = 0; i < n; i++) {
			count += (nums[i] == 1 ? 1 : -1);
			auto it = mp.find(count);
			if (it == mp.end()) {
				mp[count] = { i, i };
			}
			else {
				auto& p = it->second;
				p.first = min(p.first, i);
				p.second = max(p.second, i);
			}
		}
		int ans = 0;
		if (mp[0].second > 0) ans = mp[0].second + 1;
		for (const auto& p : mp) {
			ans = max(ans, p.second.second - p.second.first);
		}
		return ans;
	}
};