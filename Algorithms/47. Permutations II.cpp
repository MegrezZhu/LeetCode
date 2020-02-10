class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> s;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) s.push_back({ nums[i], 1 });
            else s.back().second++;
        }
        vector<vector<int>> result;
        vector<int> tmp;
        find(nums.size(), result, s, tmp);
        return result;
    }
    
    void find(int N, vector<vector<int>> &result, vector<pair<int, int>> s, vector<int> &state) {
        if (state.size() == N) {
            result.push_back(state);
            return;
        }
        for (auto &p : s) {
            if (p.second == 0) continue;
            state.push_back(p.first);
            p.second--;
            find(N, result, s, state);
            p.second++;
            state.pop_back();
        }
    }
};