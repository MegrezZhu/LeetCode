class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> flag(n, vector<bool>(n, false));
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        list<pair<int, int>> li({{0, 0}});
        dis[0][0] = grid[0][0];
        static const int dx[4] = {0, 1, 0, -1};
        static const int dy[4] = {1, 0, -1, 0};
        while (!li.empty()) {
            auto p = li.front();
            li.pop_front();
            for (int i = 0; i < 4; i++) {
                int tx = p.first + dx[i];
                int ty = p.second + dy[i];
                int from = dis[p.first][p.second];
                if (tx >= 0 && ty >= 0 && tx < n && ty < n) {
                    int to = grid[tx][ty];
                    if (max(from, to) < dis[tx][ty]) {
                        dis[tx][ty] = max(from, to);
                        if (!flag[tx][ty]) {
                            li.push_back({tx, ty});
                        }
                    }
                }
            }
            flag[p.first][p.second] = false;
        }
        return dis[n - 1][n - 1];
    }
};