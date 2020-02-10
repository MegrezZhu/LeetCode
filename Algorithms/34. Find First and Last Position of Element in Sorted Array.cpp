class Solution {
    vector<int> span(vector<int>& nums, int pos) {
        int l = pos, r = pos;
        while (l > 0 && nums[l - 1] == nums[l]) l--;
        while (r < nums.size() - 1 && nums[r + 1] == nums[r]) r++;
        return { l, r };
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return span(nums, mid);
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return {-1, -1};
    }
};