class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path = {0};
        dfs(graph, 0, path, graph.size() - 1, ans);
        return ans;
    }
private:
    void dfs(const vector<vector<int>>& graph, int p, vector<int> &path, int target, vector<vector<int>> &ans) {
        if (p == target) {
            ans.push_back(path);
            return;
        }
        for (int q : graph[p]) {
            path.push_back(q);
            dfs(graph, q, path, target, ans);
            path.pop_back();
        }
    }
};