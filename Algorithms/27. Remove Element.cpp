class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (int x : nums) {
            if (x != val) nums[len++] = x;
        }
        return len;
    }
};