class Solution {
public:
    vector<int> xorQueries(const vector<int>& arr, const vector<vector<int>>& queries) {
        vector<int> prefix, ans;
        
        for (int x : arr) prefix.push_back(x ^ (prefix.empty() ? 0 : prefix.back()));
        for (const auto& q: queries) {
            int ret = prefix[q[1]];
            if (q[0] > 0) ret ^= prefix[q[0] - 1];
            ans.push_back(ret);
        }
        
        return ans;
    }
};