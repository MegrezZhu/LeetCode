class Solution {
    int explorer(vector<vector<int>>& grid, int x, int y) {
        constexpr int dx[4] = {0, 1, 0, -1};
        constexpr int dy[4] = {1, 0, -1, 0};
        if (!grid[x][y]) return 0;
        grid[x][y] = 0;
        int count = 0;
        int n = grid.size(), m = grid.front().size();
        list<pair<int, int>> li = { {x, y} };
        while (!li.empty()) {
            auto p = li.front();
            li.pop_front();
            count++;
            for (int i = 0; i < 4; i++) {
                auto nx = p.first + dx[i];
                auto ny = p.second + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny]) {
                    grid[nx][ny] = 0;
                    li.push_back({nx, ny});
                }
            }
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid.front().size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) ans = max(ans, explorer(grid, i, j));
        }
        return ans;
    }
};