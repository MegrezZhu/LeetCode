class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> f(n + 1, false);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                f[i] = f[i] || !f[i - j * j];
                if (f[i]) break;
            }
        }
        return f[n];
    }
};