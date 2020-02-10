class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            if (n % 2) res++;
            n /= 2;
        }
        return res;
    }
};