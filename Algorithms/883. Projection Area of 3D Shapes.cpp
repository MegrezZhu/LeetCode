class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size();
        
        int sx = 0, sy = 0, sz = 0;
        for (const auto &row : grid) {
            for (int height : row) {
                sz += int(height > 0);
            }
        }
        
        for (int i = 0; i < n; i++) {
            int maxh = 0;
            for (int j = 0; j < m; j++) {
                maxh = max(maxh, grid[i][j]);
            }
            sx += maxh;
        }
        
        for (int j = 0; j < m; j++) {
            int maxh = 0;
            for (int i = 0; i < n; i++) {
                maxh = max(maxh, grid[i][j]);
            }
            sy += maxh;
        }
        
        return sx + sy + sz;
    }
};