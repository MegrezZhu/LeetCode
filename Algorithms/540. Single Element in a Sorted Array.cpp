class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid % 2) { // odd
                if (mid > 0 && nums[mid] == nums[mid - 1]) l = mid + 1;
                else if (mid + 1 < n && nums[mid] == nums[mid + 1]) r = mid - 1;
                else return nums[mid];
            } else { // even
                if (mid > 0 && nums[mid] == nums[mid - 1]) r = mid - 1;
                else if (mid + 1 < n && nums[mid] == nums[mid + 1]) l = mid + 1;
                else return nums[mid];
            }
        }
    }
};