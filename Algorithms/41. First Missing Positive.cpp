class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int p = i;
            while (nums[p] != -1 && nums[p] != p + 1) {
                if (nums[p] <= 0 || nums[p] > n) {
                    nums[p] = -1;
                } else {
                    if (nums[p] != nums[nums[p] - 1]) {
                        swap(nums[p], nums[nums[p] - 1]);
                    } else {
                        nums[p] = -1;
                    }                    
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == -1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};