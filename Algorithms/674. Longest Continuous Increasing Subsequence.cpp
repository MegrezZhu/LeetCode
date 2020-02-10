#include <initializer_list>

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (!nums.size()) return 0;
        vector<int> dp = {1};
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) dp.push_back(dp.back() + 1);
            else dp.push_back(1);
            ans = max(ans, dp.back());
        }
        return ans;
    }
};