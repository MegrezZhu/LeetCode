class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outCount(n, 0);
        vector<vector<int>> inEdge(n);
        
        list<int> li;
        for (int i = 0; i < n; i++) {
            outCount[i] = graph[i].size();
            for (int j : graph[i]) {
                inEdge[j].push_back(i);
            }
            if (outCount[i] == 0) {
                li.push_back(i);
            }
        }
        
        vector<int> result;
        while (!li.empty()) {
            int p = li.front();
            li.pop_front();
            result.push_back(p);
            
            for (int i : inEdge[p]) {
                outCount[i]--;
                if (outCount[i] == 0) {
                    li.push_back(i);
                }
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};