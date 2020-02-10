class Solution {
public:
    int numWays(int steps, int arrLen) {
        int MOD = 1e9 + 7;
        arrLen = min(arrLen, steps);
        vector<int> last(arrLen, 0), next(arrLen, 0);
        last[0] = 1;
        for (int t = 1; t <= steps; t++) {
            for (int i = 0; i < arrLen; i++) {
                next[i] = last[i];
                if (i > 0) next[i] = (next[i] + last[i - 1]) % MOD;
                if (i < arrLen - 1) next[i] = (next[i] + last[i + 1]) % MOD;
            }
            for (int i = 0; i < arrLen; i++) {
                last[i] = next[i];
            }
        }
        return last[0];
    }
};