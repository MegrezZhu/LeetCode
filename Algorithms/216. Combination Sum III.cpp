class Solution {
    int k, n;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        this->n = n;
        vector<vector<int>> ans;
        vector<int> now;
        dfs(ans, 1, now, 0);
        return ans;
    }
    void dfs(vector<vector<int>> &ans, int L, vector<int> &now, int sum) {
        if (sum == n && now.size() == k) {
            ans.push_back(now);
            return;
        }
        if (sum >= n || now.size() == k) return;
        for (int i = L; i <= 9; i++) {
            now.push_back(i);
            dfs(ans, i + 1, now, sum + i);
            now.pop_back();
        }
    }
};