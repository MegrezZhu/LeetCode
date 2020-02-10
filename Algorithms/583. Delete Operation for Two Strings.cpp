class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> f(n1 + 1, vector<int>(n2 + 1));
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (!i && !j) continue;
                f[i][j] = 1000000;
                if (i) f[i][j] = min(f[i][j], f[i - 1][j] + 1);
                if (j) f[i][j] = min(f[i][j], f[i][j - 1] + 1);
                if (i && j && word1[i - 1] == word2[j - 1]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            }
        }
        return f[n1][n2];
    }
};