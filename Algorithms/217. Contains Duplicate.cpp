class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int x : nums) {
            auto res = s.insert(x);
            if (!res.second) return true;
        }
        return false;
    }
};