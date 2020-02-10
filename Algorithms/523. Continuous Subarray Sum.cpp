class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        k = abs(k);
        unordered_set<int> s;
        int last = -1, sum = 0;
        for (int a : nums) {
            if (k) {
                sum = (sum + a) % k;
            } else {
                sum = sum + a;
            }
            if (s.find(sum) != s.end()) return true;
            if (last != -1) {
                s.insert(last);
            }
            if (last != -1 && sum == 0) return true;
            last = sum;
        }
        return false;
    }
};