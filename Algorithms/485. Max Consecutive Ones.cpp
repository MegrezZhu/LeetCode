class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            int j = i;
            while (j < nums.size() - 1 && nums[j + 1] == 1) j++;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};