class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for (int a : nums) xorr ^= a;
        int r1 = (xorr & (xorr - 1)) ^ xorr;
        int xorr1 = 0, xorr2 = 0;
        for (int a : nums) {
            if (a & r1) xorr1 ^= a;
            else xorr2 ^= a;
        }
        return { xorr1, xorr2 };
    }
};