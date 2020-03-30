class Solution {
public:
    int hammingDistance(int x, int y) {
        int d = 0;
        while (x || y) {
            d += (x & 0b1) ^ (y & 0b1);
            x >>= 1;
            y >>= 1;
        }
        return d;
    }
};