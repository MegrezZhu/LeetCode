class Solution {
    bool check(const vector<int>& stones, const vector<vector<bool>> &f, const unordered_map<int, int> &mp, int a, int b, int lap) {
        auto it = mp.find(stones[b] - lap);
        if (it == mp.end()) return false;
        return f[b][it->second];
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n == 1) return true;
        if (stones[1] != 1) return false;
        if (n == 2) return true;
        
        vector<vector<bool>> f(n, vector<bool>(n, false));
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) mp.insert(make_pair(stones[i], i));
        f[1][0] = true;
        for (int i = 2; i < n; i++) {
            for (int j = 1; j < i; j++) {
                int lap = stones[i] - stones[j];
                f[i][j] = check(stones, f, mp, i, j, lap) || check(stones, f, mp, i, j, lap - 1) || check(stones, f, mp, i, j, lap + 1);
                if (i == n - 1 && f[i][j]) return true;
            }
        }
        
        return false;
    }
};