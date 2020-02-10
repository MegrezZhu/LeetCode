class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        size_t n = people.size();
        vector<pair<int, int>> d(n);
        for (int i = 0; i < n; i++) {
            d[i].first = people[i][0];
            d[i].second = people[i][1];
        }
        sort(d.begin(), d.end());
        vector<vector<int>> ans(n);
        for (auto &p : d) {
            int left = p.second;
            for (int i = 0; i < n; i++) {
                if (!left && ans[i].empty()) {
                    ans[i].push_back(p.first);
                    ans[i].push_back(p.second);
                    break;
                }
                if (ans[i].empty() || ans[i][0] == p.first) left--;
            }
        }
        return ans;
    }
};