class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = 0; a == 0 || a <= c / a; a++) {
            int b = sqrt(c - a * a);
            if (a * a + b * b == c) {
                return true;
            }
        }
        return false;
    }
};