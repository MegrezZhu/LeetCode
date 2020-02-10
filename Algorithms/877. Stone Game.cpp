class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<pair<int, int>>> f(n, vector<pair<int, int>>(n + 1));
        for (int i = 0; i < n; i++) {
            f[i][0] = make_pair(0, 0);
            f[i][1] = make_pair(piles[i], 0);
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n; i++) {
                int l = i, r = i + len - 1;
                if (r >= n) continue;
                if (piles[l] + f[i + 1][len - 1].second > f[i][len - 1].second + piles[r]) {
                    const auto &from = f[i + 1][len - 1];
                    f[i][len] = make_pair(piles[l] + from.second, from.first);
                } else {
                    const auto &from = f[i][len - 1];
                    f[i][len] = make_pair(from.second + piles[r], from.first);
                }
            }
        }
        return f[0][n].first > f[0][n].second;        
    }
};