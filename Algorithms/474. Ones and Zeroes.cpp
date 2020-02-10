class Solution {
    pair<int, int> count(const string &s) {
        int zero = 0, one = 0;
        for (char ch : s) {
            if (ch == '0') zero++;
            if (ch == '1') one++;
        }
        return {zero, one};
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        for (const string &s : strs) {
            auto p = count(s);
            for (int i = m; i >= p.first; i--) {
                for (int j = n; j >= p.second; j--) {
                    f[i][j] = max(f[i][j], f[i - p.first][j - p.second] + 1);
                }
            }
        }
        return f[m][n];
    }
};