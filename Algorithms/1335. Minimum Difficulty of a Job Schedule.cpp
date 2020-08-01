class Solution {
public:
    int minDifficulty(vector<int>& jobs, int d) {
        int n = jobs.size();
        vector<vector<int>> f(d, vector<int>(n, 1e9));
        
        f[0][0] = jobs[0];
        for (int i = 1; i < n; i++) {
            f[0][i] = max(f[0][i - 1], jobs[i]);
        }
        
        for (int i = 1; i < d; i++) {
            for (int j = n - 1; j >= i; j--) {
                int maxx = jobs[j];
                for (int k = j - 1; k >= 0; k--) {
                    f[i][j] = min(f[i][j], f[i - 1][k] + maxx);
                    maxx = max(maxx, jobs[k]);
                }
            }
        }
        return f[d - 1][n - 1] != 1e9 ? f[d - 1][n - 1] : -1;
    }
};