class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (size_t i = 0; i < nums.size(); i++) {
            int p = i;
            while (nums[p] != p + 1 && nums[p] != -1) {
                if (nums[nums[p] - 1] == nums[p]) {
                    res.push_back(nums[p]);
                    nums[p] = -1;
                    break;
                }
                swap(nums[p], nums[nums[p] - 1]);
            }
        }
        return res;
    }
};