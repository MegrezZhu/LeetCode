class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mov = 0;
        for (int x : nums) mov += abs(x - nums[n / 2]);
        return mov;
    }
};