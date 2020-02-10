class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<list<pair<int, int>>> e(N + 1);
        for (const auto &v : times) {
            int from = v[0], to = v[1], cost = v[2];
            e[from].push_back({to, cost});
        }
        list<int> li = {K};
        vector<int> dis(N + 1, 1e9);
        vector<bool> flag(N + 1, false);
        dis[K] = dis[0] = 0;
        flag[K] = true;
        while (!li.empty()) {
            int from = li.front();
            li.pop_front();
            for (const auto &p : e[from]) {
                int to = p.first, cost = p.second;
                if (dis[from] + cost < dis[to]) {
                    dis[to] = dis[from] + cost;
                    if (!flag[to]) {
                        flag[to] = true;
                        li.push_back(to);
                    }
                }
            }
            flag[from] = false;
        }
        int ans = 0;
        for (int time : dis) ans = max(ans, time);
        return ans == 1e9 ? -1 : ans;
    }
};