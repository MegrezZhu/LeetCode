class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> f(nums.size()), g(nums.size());
        int ans = -2e9;
        for (int i = 0; i < nums.size(); i++) {
            f[i] = g[i] = nums[i];
            if (i) {
                f[i] = max(f[i], nums[i] * f[i - 1]);
                f[i] = max(f[i], nums[i] * g[i - 1]);
                g[i] = min(g[i], nums[i] * f[i - 1]);
                g[i] = min(g[i], nums[i] * g[i - 1]);
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};