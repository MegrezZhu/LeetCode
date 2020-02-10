class Solution {
public:
	void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (k == 0) return;
		int l = 0, r = nums.size() - 1;
		while (true) {
			int n = r - l + 1;
			int left = n - k, right = k;
			if (left == right) {
				swapV(nums, l, r, k);
				break;
			}
			else {
				if (left < right) {
					swapV(nums, l, r, left);
					r -= left;
					k = right - left;
				}
				else {
					swapV(nums, l, r, right);
					l += right;
					k = right;
				}
			}
		}
	}
	void swapV(vector<int> &nums, int l, int r, int len) {
		int n = r - l + 1;
		for (int i = 0; i < len; i++) {
			swap(nums[l + i], nums[l + n - len + i]);
		}
	}
};