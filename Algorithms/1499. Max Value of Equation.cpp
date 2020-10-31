class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        list<tuple<int, int>> q; // <xi, val = -xi + yi>
        int ans = -1e9;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            while (!q.empty() && x - get<0>(q.front()) > k) {
                q.pop_front();
            }
            if (!q.empty()) {
                ans = max(ans, x + y + get<1>(q.front()));
            }
            int val = -x + y;
            while (!q.empty() && get<1>(q.back()) <= val) {
                q.pop_back();
            }
            q.push_back({x, val});
        }
        return ans;
    }
};