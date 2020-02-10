class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        constexpr int dx[4] = { 0, 1, 0, -1 };
        constexpr int dy[4] = { 1, 0, -1, 0 };
        int dir = 0;
        vector<vector<int>> res(n, vector<int>(n, -1));
        for (int i = 1, x = 0, y = 0; i <= n * n; i++) {
            res[x][y] = i;
            int tx = x + dx[dir], ty = y + dy[dir];
            if (tx < 0 || ty < 0 || tx >= n || ty >= n || res[tx][ty] != -1) {
                dir = (dir + 1) % 4;
            }
            x += dx[dir];
            y += dy[dir];
        }
        return res;
    }
};