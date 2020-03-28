class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums.back() - nums.front();
        int ans = 1e9;
        while (l <= r) {
            int mid = (l + r) / 2;
            int c = count(nums, mid);
            if (c >= k) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    
    int count(const vector<int> &nums, int D) {
        int ans = 0;
        for (int l = 0, r = 1; r < nums.size(); r++) {
            while (nums[l] + D < nums[r]) l++;
            ans += r - l;
        }
        return ans;
    }
};