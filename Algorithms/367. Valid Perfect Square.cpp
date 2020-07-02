class Solution {
public:
    bool isPerfectSquare(int num) {
        const static int MAX = 46340; // sqrt(2 ^ 31 - 1)
        int l = 1, r = min(num, MAX);
        while (l <= r) {
            int m = (l + r) / 2;
            int square = m * m;
            if (num == square) {
                return true;
            } else if (num < square) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return false;
    }
};