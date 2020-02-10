class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int, int> mp;
        int n = difficulty.size(), m = worker.size();
        for (int i = 0; i < n; i++) {
            int diff = difficulty[i], prof = profit[i];
            auto it = mp.find(diff);
            if (it == mp.end()) {
                mp.insert({diff, prof});
            } else {
                it->second = max(it->second, prof);
            }
        }
        int prof = 0;
        for (auto &p : mp) {
            prof = max(prof, p.second);
            p.second = prof;
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int ability = worker[i];
            auto it = mp.upper_bound(ability);
            if (it == mp.begin()) continue;
            it--;
            ans += it->second;
        }
        return ans;
    }
};