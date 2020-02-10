class Solution {
public:
	int rob(vector<int>& nums) {
		vector<int> f(nums.size() + 1);
		f[0] = 0;
		for (int i = 1; i <= nums.size(); i++) {
			f[i] = max(f[i - 1], nums[i - 1]);
			if (i > 1) f[i] = max(f[i], f[i - 2] + nums[i - 1]);
		}
		return f[nums.size()];
	}
};