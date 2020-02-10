class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {{newInterval[0], newInterval[1]}};
        vector<vector<int>> ans;
        int l = newInterval[0], r = newInterval[1];
        for (auto &p : intervals) {
            if (l >= p[0] && l <= p[1] || r >= p[0] && r <= p[1] || l <= p[0] && r >= p[1]) {
                l = min(l, p[0]);
                r = max(r, p[1]);
            } else {
                if (r < p[0]) {
                    ans.push_back({l, r});
                    l = 1e9;
                    r = 1e9 + 1;
                }
                ans.push_back(move(p));
            }
        }
        if (l != 1e9) ans.push_back({l, r});
        return ans;
    }
};