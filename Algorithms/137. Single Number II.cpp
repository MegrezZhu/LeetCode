class Solution {
	int countBits(vector<int>& nums, int pos) {
		int count = 0;

		int mask = 1 << pos;
		for (int c : nums) {
			if (c & mask) count++;
		}

		return count;
	}
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (int i = 0; i < 32; i++) {
			if (countBits(nums, i) % 3) result += 1 << i;
		}
		return result;
	}
};