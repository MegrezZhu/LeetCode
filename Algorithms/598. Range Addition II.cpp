class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.empty()) return m * n;
        int min1 = m, min2 = n;
        for (const auto &p : ops) {
            min1 = min(min1, p[0]);
            min2 = min(min2, p[1]);
        }
        return min1 * min2;
    }
};