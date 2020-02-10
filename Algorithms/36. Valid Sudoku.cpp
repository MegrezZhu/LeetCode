class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<bool> flag(9, false);
            for (int j = 0; j < 9; j++) { // rows
                if (board[i][j] == '.') continue;
                if (flag[board[i][j] - '0']) return false;
                else flag[board[i][j] - '0'] = true;
            }
            vector<bool> flag1(9, false);
            for (int j = 0; j < 9; j++) { // cols
                if (board[j][i] == '.') continue;
                if (flag1[board[j][i] - '0']) return false;
                else flag1[board[j][i] - '0'] = true;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                vector<bool> flag(9, false);
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        int xx = x + i * 3;
                        int yy = y + j * 3;
                        if (board[xx][yy] == '.') continue;
                        if (flag[board[xx][yy] - '0']) return false;
                        else flag[board[xx][yy] - '0'] = true;
                    }
                }
            }
        }
        return true;
    }
};