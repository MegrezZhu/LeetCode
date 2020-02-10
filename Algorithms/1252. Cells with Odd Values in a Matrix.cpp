class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> row(n, 0), col(m, 0);
        for (const auto& v: indices) {
            int r = v[0], c = v[1];
            row[r]++;
            col[c]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((row[i] + col[j]) % 2 == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};