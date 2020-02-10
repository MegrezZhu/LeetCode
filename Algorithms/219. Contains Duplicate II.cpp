class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // <val, count>
        int l = 0, r = -1;
        while (r + 1 < nums.size()) {
            if (r - l + 1 == k + 1) {
                mp[nums[l]] -= 1;
                l++;
            } else {
                r++;
                auto &v = mp[nums[r]];
                if (v > 0) return true;
                v += 1;
            }
        }
        return false;
    }
};