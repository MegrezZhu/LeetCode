class Solution {
    const vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
public:
    bool containsCycle(const vector<vector<char>>& grid) {
        int n = grid.size(), m = grid.front().size();
        vector<vector<int>> flag(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (flag[i][j] != 0) continue;
                count++;
                if (dfs(grid, flag, {i, j}, {-10000, -10000}, count)) return true;
            }
        }
        return false;
    }
private:
    bool dfs(const vector<vector<char>> &grid, vector<vector<int>> &flag, tuple<int, int> pos, tuple<int, int> from, int round) {
        auto [x, y] = pos;
        int n = grid.size(), m = grid.front().size();
        if (flag[x][y] == 0) {
            flag[x][y] = round;
            for (int i = 0; i < 4; i++) {
                auto [fx, fy] = from;
                int tx = x + dx[i], ty = y + dy[i];
                if (tx >= 0 && ty >= 0 && tx < n && ty < m && (tx != fx || ty != fy) && grid[tx][ty] == grid[x][y]) {
                    bool res = dfs(grid, flag, {tx, ty}, pos, round);
                    if (res) return true;
                }
            }
        } else {
            return flag[x][y] == round;
        }
        return false;
    }
};