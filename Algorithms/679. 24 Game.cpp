class Solution {
public:
	bool judgePoint24(const vector<int>& nums) {
		vector<double> s;
		vector<bool> flag(nums.size(), false);
		return dfs(nums, 0, s, flag);
	}

	bool dfs(const vector<int>& nums, int L, vector<double>& s, vector<bool>& flag) {
		if (L == nums.size() && s.size() == 1) {
			return fabs(24 - s.back()) < 1e-6;
		}
		if (s.size() >= 2) {
			double t1 = s[s.size() - 2], t2 = s[s.size() - 1];
			s.pop_back();
			s.back() = t1 + t2;
			if (dfs(nums, L, s, flag)) return true;
			s.back() = t1 - t2;
			if (dfs(nums, L, s, flag)) return true;
			s.back() = t1 * t2;
			if (dfs(nums, L, s, flag)) return true;
			s.back() = t1 / t2;
			if (dfs(nums, L, s, flag)) return true;

			s.back() = t1;
			s.push_back(t2);
		}
		for (int i = 0; i < nums.size(); i++) {
			if (!flag[i]) {
				s.push_back(nums[i]);
				flag[i] = true;
				if (dfs(nums, L + 1, s, flag)) return true;
				s.pop_back();
				flag[i] = false;
			}
		}
		return false;
	}
};