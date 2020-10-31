class Solution {
public:
    int numberOfArrays(const string& s, int k) {
        static const int MOD = 1e9 + 7;

        int n = s.length();
        vector<int> f(n + 1, 0);
        f[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i, x = 0; j < n; j++) {
                if (x > 1e8) {
                    break;
                }
                x = x * 10 + (s[j] - '0');
                if (x > 0 && x <= k) {
                    f[i] = (f[i] + f[j + 1]) % MOD;
                } else {
                    break;
                }
            }
        }
        return f[0];
    }
};