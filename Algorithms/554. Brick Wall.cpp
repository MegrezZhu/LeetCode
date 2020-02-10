class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> s; // seams
        for (const auto& row : wall) {
            int sum = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                sum += row[i];
                s[sum] += 1;
            }
        }
        
        int n = wall.size();
        int ans = n;
        for (const auto &p : s) {
            ans = min(ans, n - p.second);
        }
        return ans;
    }
};