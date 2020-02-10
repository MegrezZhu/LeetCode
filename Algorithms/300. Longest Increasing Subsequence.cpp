class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> f(nums.size() + 1, 2e9);
		f[0] = -2e9;
		int ans = 0;
		for (auto x : nums) {
			int l = 0, r = nums.size();
			int maxOk = 0;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (f[mid] < x) {
					l = mid + 1;
					maxOk = mid;
				}
				else r = mid - 1;
			}
			f[maxOk + 1] = min(f[maxOk + 1], x);
			ans = max(ans, maxOk + 1);
		}
		return ans;
	}
};