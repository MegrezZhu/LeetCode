class Solution {
public:
	int findMin(const vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			if (nums[l] < nums[r]) return nums[l];
			int mid = (l + r) / 2;
			if (nums[mid] < nums[r]) r = mid;
			else if (nums[mid] > nums[l]) l = mid + 1;
			else l++;
		}
		return nums[l];
	}
};