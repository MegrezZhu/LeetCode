class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (int x : nums) sum += x;
		if (sum % 2) return false;
		vector<bool> f(sum / 2 + 1);
		f[0] = true;
		for (int i = 1; i < nums.size(); i++) {
			for (int j = sum / 2; j >= 0; j--) {
				if (j - nums[i] >= 0) f[j] = f[j] || f[j - nums[i]];
			}
		}
		return f[sum / 2];
	}
};