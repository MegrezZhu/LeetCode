class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int firstZero = -1;
		for (size_t i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				if (firstZero >= 0 && firstZero < nums.size() && firstZero < i) {
					swap(nums[firstZero], nums[i]);
					while (firstZero < nums.size() && nums[firstZero]) firstZero++;
				}
			}
			else if (firstZero == -1) {
				firstZero = i;
			}
		}
	}
};