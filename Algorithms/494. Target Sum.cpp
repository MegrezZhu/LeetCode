class Solution {
public:
    int findTargetSumWays(const vector<int>& nums, long long S, size_t pos = 0) {
        if (pos == nums.size()) return S == 0 ? 1 : 0;
        return findTargetSumWays(nums, S - nums[pos], pos + 1) + findTargetSumWays(nums, S + nums[pos], pos + 1);
    }
};