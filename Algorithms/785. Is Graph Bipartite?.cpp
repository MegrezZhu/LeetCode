class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> mark(n, 0); // 0 for not decided, 1/2 for group
        for (int i = 0; i < n; i++) {
            if (mark[i] != 0) continue;
            mark[i] = 1;
            list<int> li({i});
            while (!li.empty()) {
                int p = li.front();
                li.pop_front();
                for (auto j : graph[p]) {
                    if (mark[j] == mark[p]) {
                        return false; // same group
                    }
                    if (mark[j] == 0) {
                        mark[j] = 3 - mark[p];
                        li.push_back(j);
                    }
                }
            }
        }
        return true;
    }
};