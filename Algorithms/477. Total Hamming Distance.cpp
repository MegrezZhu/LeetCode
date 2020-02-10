class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for (int bit = 1; bit > 0 && bit < 2e9; bit <<= 1) {
            int one = 0, zero = 0;
            for (int x : nums) {
                if (x & bit) {
                    one++;
                } else {
                    zero++;
                }
            }
            ans += one * zero;
        }
        return ans;
    }
};