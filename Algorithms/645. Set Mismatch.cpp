class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int mis, dup;
        for (int i = 0; i < nums.size(); i++) {
            int p = i;
            while (nums[p] != p + 1 && nums[p] != 0) {
                int to = nums[p] - 1;
                if (nums[p] != nums[to]) {
                    swap(nums[p], nums[to]);
                } else {
                    dup = nums[p];
                    nums[p] = 0;
                    break;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                mis = i + 1;
                break;
            }
        }
        return { dup, mis };
    }
};