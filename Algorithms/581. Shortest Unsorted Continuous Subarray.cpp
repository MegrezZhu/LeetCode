class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto sorted = nums;
        sort(sorted.begin(), sorted.end());
        int l = 0, r = nums.size() - 1;
        while (nums[l] == sorted[l] && l < r) l++;
        while (nums[r] == sorted[r] && r > l) r--;
        if (l == r) return 0;
        return r - l + 1;
    }
};