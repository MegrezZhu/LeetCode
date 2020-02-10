class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int l = 0, r = 0, s = 1; r < n; r++) {
            s *= nums[r];
            while (s >= k && l <= r) {
                s /= nums[l];
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};