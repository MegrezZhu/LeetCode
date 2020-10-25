class Solution {
public:
    int minimumEffortPath(const vector<vector<int>>& h) {
        int n = h.size(), m = h.front().size();
        vector<vector<int>> e(n, vector<int>(m, int(1e9))); // effort
        vector<vector<bool>> flag(n, vector<bool>(m));
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        list<pair<int, int>> li = {{0, 0}};
        flag[0][0] = true;
        e[0][0] = 0;
        while (!li.empty()) {
            auto [x, y] = li.front();
            flag[x][y] = false;
            li.pop_front();
            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx >= 0 && ty >= 0 && tx < n && ty < m) {
                    int ef = max(e[x][y], abs(h[x][y] - h[tx][ty]));
                    if (ef < e[tx][ty]) {
                        e[tx][ty] = ef;
                        if (!flag[tx][ty]) {
                            flag[tx][ty] = true;
                            li.push_back({tx, ty});
                        }
                    }
                }
            }
        }
        return e[n - 1][m - 1];
    }
};