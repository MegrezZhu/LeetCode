class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        int ans = 0;
        while (n - 1 > r) {
            int rightMost = 0;
            ans++;
            for (int i = l; i <= r; i++) rightMost = max(rightMost, i + nums[i]);
            l = r + 1;
            r = rightMost;
        }
        return ans;
    }
};