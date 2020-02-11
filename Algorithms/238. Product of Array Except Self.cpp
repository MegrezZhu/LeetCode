class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 0, p = 1; i < n; i++) {
            res[i] *= p;
            p *= nums[i];
        }
        for (int i = n - 1, p = 1; i >= 0; i--) {
            res[i] *= p;
            p *= nums[i];
        }
        
        return res;
    }
};