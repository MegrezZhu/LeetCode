class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> dp(target + 1, 0);
        const int MOD = 1e9 + 7;
        dp[0] = 1;
        for (int i = 0; i < d; i++) {
            int sum = 0, p = target - 1;
            while (p >= 0 && p + f >= target) {
                sum = (sum + dp[p]) % MOD;
                p--;
            }
            
            for (int j = target; j >= 0; j--) {
                dp[j] = sum;
                if (j > 0) {
                    sum = (sum - dp[j - 1] + MOD) % MOD;
                }
                if (j >= f + 1) {
                    sum = (sum + dp[j - f - 1]) % MOD;
                }
            }
        }
        return dp[target];
    }
};