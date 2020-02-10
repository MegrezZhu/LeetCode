class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightSum(n, 0);
        for (int i = n - 2; i >= 0; i--) rightSum[i] = rightSum[i + 1] + nums[i + 1];
        for (int i = 0, sum = 0; i < n; i++) {
            if (sum == rightSum[i]) return i;
            sum += nums[i];
        }
        return -1;
    }
};