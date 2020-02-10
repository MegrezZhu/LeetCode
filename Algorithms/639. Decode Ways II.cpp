class Solution {
    inline bool isNonZero(char a) {
        return a > '0' && a <= '9';
    }
    inline bool isNum(char a) {
        return a >= '0' && a <= '9';
    }
public:
    int numDecodings(string s) {
        constexpr long long MOD = 1e9 + 7;
        if (!s.length()) return 0;
        vector<long long> f(s.length() + 1);
        f[0] = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') f[i + 1] = (f[i] * 9) % MOD;
            else if (isNonZero(s[i])) f[i + 1] = f[i];
            else f[i] = 0;
            
            if (i == 0) continue;
            if (isNonZero(s[i - 1])) {
                if (isNum(s[i])) {
                    if (s[i - 1] * 10 + s[i] - 11 * '0' <= 26) f[i + 1] = (f[i + 1] + f[i - 1]) % MOD;
                } else if (s[i] == '*') {
                    int fac = 0;
                    if (s[i - 1] == '1') fac = 9;
                    else if (s[i - 1] == '2') fac = 6;
                    f[i + 1] = (f[i + 1] + fac * f[i - 1]) % MOD;
                }
            } else if (s[i - 1] == '*') {
                if (s[i] == '*') f[i + 1] = (f[i + 1] + f[i - 1] * 15) % MOD; // 11~19, 21~26
                else if (isNum(s[i])) {
                    f[i + 1] = (f[i + 1] + (s[i] <= '6' ? 2 : 1) * f[i - 1]) % MOD;
                }
            }
        }
        return f[s.length()];
    }
};