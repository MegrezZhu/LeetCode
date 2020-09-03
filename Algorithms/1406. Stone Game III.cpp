class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();
        vector<pair<int, int>> f(n);
        for (int i = n - 1; i >= 0; i--) {
            f[i] = { -1e9, 0 };
            for (int j = 1, sum = 0; j <= 3 && i + j - 1 < n; j++) {
                sum += stones[i + j - 1];
                auto [first, second] = i + j < n ? f[i + j] : make_pair(0, 0);
                if (sum + second > f[i].first || sum + second == f[i].first && first < f[i].second) {
                    f[i] = { sum + second, first };
                }
            }
        }
        auto [a, b] = f[0];
        if (a < b) return "Bob";
        if (a > b) return "Alice";
        return "Tie";
    }
};