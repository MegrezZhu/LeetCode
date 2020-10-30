class Solution {
public:
    bool kLengthApart(const vector<int>& nums, int k) {
        for (int i = 0, last = -k - 1; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            if (i - last - 1 < k) return false;
            last = i;
        }
        return true;
    }
};