class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), m = board.front().length();
        vector<vector<pair<int, int>>> f(n, vector<pair<int, int>>(m, { 0, 0 })); // < max_sum, count >
        
        f[n - 1][m - 1] = { 0, 1 };
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (board[i][j] == 'X') continue;
                
                if (i + 1 < n) update(i, j, 1, 0, board, f);
                if (j + 1 < m) update(i, j, 0, 1, board, f);
                if (i + 1 < n && j + 1 < m) update(i, j, 1, 1, board, f);
            }
        }
        
        return { f[0][0].second > 0 ? f[0][0].first : 0, f[0][0].second };
    }
    
    void update(int x, int y, int dx, int dy, const vector<string>& board, vector<vector<pair<int, int>>> &f) {
        static const int MOD = 1e9 + 7;
        int val = 0;
        if (board[x][y] >= '0' && board[x][y] <= '9') val = board[x][y] - '0';
        int newSum = val + f[x + dx][y + dy].first;
        if (newSum == f[x][y].first) {
            f[x][y].second = (f[x][y].second + f[x + dx][y + dy].second) % MOD;
        } else if (newSum > f[x][y].first) {
            f[x][y].first = newSum;
            f[x][y].second = f[x + dx][y + dy].second;
        }
    }
};