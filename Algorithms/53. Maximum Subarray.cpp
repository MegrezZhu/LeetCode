class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> f;
        f.resize(nums.size());
        f[0] = nums[0];
        int ans = f[0];
        for (int i = 1; i < nums.size(); i++) {
            f[i] = max(f[i - 1], 0) + nums[i];
            ans = max(ans, f[i]);
        }
        return ans;
    }
};