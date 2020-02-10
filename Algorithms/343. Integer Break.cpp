class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i] = 0;
            for (int j = 0; j < i; j++) f[i] = max(f[i], f[j] * (i - j));
        }
        return f[n];
    }
};