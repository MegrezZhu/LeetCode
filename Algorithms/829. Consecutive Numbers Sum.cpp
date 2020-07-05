class Solution {
    int consecutiveSum(int from, int len) {
        return (from + from + len - 1) * len / 2;
    }
public:
    int consecutiveNumbersSum(int N) {
        const int MAX_LEN = ceil(sqrt(N * 2 + 0.25) - 0.5);
        int count = 0;
        for (int len = MAX_LEN; len >= 1; len--) {
            int x = ceil(N / double(len) - len / 2.0 + 0.5);
            if (consecutiveSum(x, len) == N) {
                count++;
            }
        }
        return count;
    }
};