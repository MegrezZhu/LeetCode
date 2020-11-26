class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> f(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i && j) f[i][j] = max(f[i][j], f[i - 1][j - 1]);
                if (text1[i] == text2[j]) {
                    f[i][j] += 1;
                }
                if (i > 0) f[i][j] = max(f[i][j], f[i - 1][j]);
                if (j > 0) f[i][j] = max(f[i][j], f[i][j - 1]);
            }
        }
        return f[text1.length() - 1][text2.length() - 1];
    }
};