class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        int maxn = 0;
        for (const auto &route : routes) {
            for (int stop : route) {
                maxn = max(maxn, stop);
            }
        }
        vector<vector<int>> stopToRoute(maxn + 1);
        vector<bool> routeTaken(maxn + 1, false);
        for (int i = 0; i < routes.size(); i++) {
            const auto &route = routes[i];
            for (int stop : route) {
                stopToRoute[stop].push_back(i);
            }
        }
        vector<int> dis(maxn + 1, -1);
        dis[S] = 0;
        list<int> li = { S };
        while (!li.empty()) {
            int f = li.front();
            li.pop_front();
            for (int route : stopToRoute[f]) {
                if (!routeTaken[route]) {
                    routeTaken[route] = true;
                    for (int stop : routes[route]) {
                        if (dis[stop] == -1) {
                            dis[stop] = dis[f] + 1;
                            if (stop == T) {
                                return dis[stop];
                            }
                            li.push_back(stop);
                        }
                    }
                }
            }
        }
        return -1;
    }
};