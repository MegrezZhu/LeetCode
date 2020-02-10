class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (!m) return 0;
        int n = obstacleGrid.front().size();
        
        vector<vector<int>> f(m, vector<int>(n, 0));
        f[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i || j) f[i][j] = 0;
                if (obstacleGrid[i][j] == 1) continue;
                if (i) f[i][j] += f[i - 1][j];
                if (j) f[i][j] += f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};