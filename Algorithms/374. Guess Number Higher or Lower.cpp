// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (true) {
            int m = ((long long)l + r) / 2;
            int res = guess(m);
            if (res == 0) return m;
            if (res < 0) r = m - 1;
            else l = m + 1;
        }
    }
};