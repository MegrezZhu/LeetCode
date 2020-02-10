class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid.front().size();
        
        vector<vector<int>> f(m, vector<int>(n, 0));
        f[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i || j) f[i][j] = 2e9;
                if (i) f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
                if (j) f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
            }
        }
        return f[m - 1][n - 1];
    }
};