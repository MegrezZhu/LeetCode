class Solution {
public:
    int arrangeCoins(int n) {
        return floor(sqrt(2 * double(n) + 0.25) - 0.5);
    }
};