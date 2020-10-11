class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> link(n);
        for (int i = 0; i < roads.size(); i++) {
            const auto &r = roads[i];
            link[r[0]].insert(i);
            link[r[1]].insert(i);
        }
        int ans = 0;
        for (int i = 0; i + 1< n; i++) {
            for (int j = i + 1; j < n; j++) {
                int count = link[i].size();
                for (int r : link[j]) {
                    if (link[i].find(r) == link[i].end()) count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};