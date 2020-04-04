class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        
        vector<int> state;
        vector<bool> flag(candidates.size(), false);
        dfs(0, target, state, 0, flag, candidates, ans);
        
        return ans;
    }
    
    void dfs(int L, int target, vector<int> &state, int stateSum, vector<bool> &flag, const vector<int> &cands, vector<vector<int>> &ans) {
        if (stateSum == target) {
            ans.push_back(state);
            return;
        }
        if (L >= cands.size()) return;
        
        dfs(L + 1, target, state, stateSum, flag, cands, ans);
        if (stateSum + cands[L] <= target) {
            if (L == 0 || cands[L - 1] != cands[L] || flag[L - 1]) {
                flag[L] = true;
                state.push_back(cands[L]);
                dfs(L + 1, target, state, stateSum + cands[L], flag, cands, ans);
                state.pop_back();   
                flag[L] = false;
            }
        }
    }
};