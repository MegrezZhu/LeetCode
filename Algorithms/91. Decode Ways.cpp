class Solution {
public:
    int numDecodings(string s) {
        if (!s.length()) return 0;
        vector<int> f(s.length() + 1);
        f[0] = 1;
        for (int i = 0; i < s.length(); i++) {
            f[i + 1] = (s[i] > '0' && s[i] <= '9') ? f[i] : 0;
            if (i > 0) {
                if (s[i - 1] <= '0' || s[i - 1] > '9') continue;
                if (s[i - 1] < '0' || s[i - 1] > '9') continue;
                if (s[i - 1] * 10 + s[i] - 11 * '0' <= 26) f[i + 1] += f[i - 1]; 
            }
        }
        return f[s.length()];
    }
};