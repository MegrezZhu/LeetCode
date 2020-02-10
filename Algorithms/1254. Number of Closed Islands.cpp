class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
        int count = 0;
        
        int n = grid.size(), m = grid.front().size();
        vector<vector<bool>> f(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !f[i][j]) {
                    f[i][j] = true;
                    list<pair<int, int>> li = {{i, j}};
                    bool valid = true;
                    while (!li.empty()) {
                        auto p = li.front();
                        li.pop_front();
                        for (int i = 0; i < 4; i++) {
                            int tx = p.first + dx[i], ty = p.second + dy[i];
                            if (tx >= 0 && ty >= 0 && tx < n && ty < m) {
                                if (grid[tx][ty] == 0 && !f[tx][ty]) {
                                    f[tx][ty] = true;
                                    li.push_back({tx, ty});
                                }
                            } else {
                                valid = false;
                            }
                        }
                    }
                    if (valid) count++;
                }
            }
        }
        
        return count;
    }
};