class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        typedef long INT;
        map<INT, int> mp; // <val, count>
        int l = 0, r = -1;
        while (r + 1 < nums.size()) {
            if (r - l + 1 == k + 1) {
                auto &v = mp[nums[l]];
                v -= 1;
                if (!v) mp.erase(nums[l]);
                l++;
            } else {
                r++;
                
                INT up = INT(nums[r]) + t, low = INT(nums[r]) - t;
                auto it1 = mp.lower_bound(low);
                if (it1 != mp.end() && it1->first <= up) return true;
                auto it2 = mp.upper_bound(up);
                if (it2 != mp.begin()) {
                    it2--;
                    if (it2->first >= low) return true;
                }
                
                // add
                auto &v = mp[nums[r]];
                v += 1;
            }
        }
        return false;
    }
};

