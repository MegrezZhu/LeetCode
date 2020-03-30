class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, 1e9);
        f[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            int x = i * i;
            for (int j = x; j <= n; j++) {
                f[j] = min(f[j], f[j - x] + 1);
            }
        }
        return f[n];
    }
};