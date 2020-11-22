class Solution {
public:
	int numSquarefulPerms(const vector<int>& A) {
		vector<bool> used(A.size());
		return dfs(A, 0, -1, used);
	}

	int dfs(const vector<int>& nums, int L, int last, vector<bool> &used) {
		if (L == nums.size()) {
			return 1;
		}

		unordered_set<int> seen;
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			auto x = nums[i];
			if (used[i] || seen.find(x) != seen.end() || last >= 0 && !isSquareful(last, x)) {
				continue;
			}
			seen.insert(x);
			used[i] = true;
			count += dfs(nums, L + 1, x, used);
			used[i] = false;
		}

		return count;
	}

	bool isSquareful(int a, int b) {
		auto r = sqrt(a + b);
		return r - floor(r) < 1e-8;
	}
};