class Solution {
    int gcd(int a, int b) {
        int r = a % b;
        return r == 0 ? b : gcd(b, r);
    }
public:
    bool isGoodArray(vector<int>& nums) {
        int res = nums[0];
        for (int x : nums) {
            res = gcd(res, x);
        }
        return res == 1;
    }
};