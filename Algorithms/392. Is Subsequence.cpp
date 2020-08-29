class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0) return true;
        if (t.length() == 0) return false;
        int n = s.length(), m = t.length();
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = f[i][j - 1];
                if (i > 0 && s[i - 1] == t[j - 1]) {
                    f[i][j] = f[i][j] || f[i - 1][j - 1];
                }
            }
        }
        return f[n][m];
    }
};