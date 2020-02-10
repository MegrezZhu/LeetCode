class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = 2147483647;
        for (int i = 0, pos = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (pos <= i && sum - nums[pos] >= s) sum -= nums[pos++];
            if (sum >= s) ans = min(ans, i - pos + 1);
        }
        return ans == 2147483647 ? 0 : ans;
    }
};