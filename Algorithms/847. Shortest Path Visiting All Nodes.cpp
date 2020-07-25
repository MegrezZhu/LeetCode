class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if (graph.size() == 1) return 0;
        int ans = 1e9;
        for (int i = 0; i < graph.size(); i++) {
            ans = min(ans, shortestPathStartedAtPos(graph, i));
        }
        return ans;
    }
    
    int shortestPathStartedAtPos(const vector<vector<int>> &graph, int start) {
        int n = graph.size();
        vector<vector<int>> flag(n, vector<int>(1 << n, 1e9));

        flag[start][1 << start] = 0;
        list<int> li = { start };
        vector<bool> inList(n, false);
        inList[start] = true;
        int ans = 1e9;
        while (!li.empty()) {
            int p = li.front();
            li.pop_front();
            for (int q : graph[p]) {
                for (int state = 0; state < (1 << n); state++) {
                    if (flag[p][state] == 1e9) continue;
                    int newState = state | (1 << q);
                    if (flag[p][state] + 1 < flag[q][newState]) {
                        flag[q][newState] = flag[p][state] + 1;
                        if (newState == (1 << n) - 1) {
                            ans = min(ans, flag[q][newState]);
                        }
                        if (!inList[q]) {
                            inList[q] = true;
                            li.push_back(q);
                        }
                    }
                }
            }
            inList[p] = false;
        }
        return ans;
    }
};