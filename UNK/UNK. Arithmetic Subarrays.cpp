class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> ans(m);
        for (int i = 0; i < m; i++) {
            vector<int> sub(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(sub.begin(), sub.end());
            int gap = sub[1] - sub[0];
            ans[i] = true;
            for (int j = 1; j < sub.size(); j++) {
                if (sub[j] - sub[j - 1] != gap) {
                    ans[i] = false;
                    break;
                }
            }
        }
        return ans;
    }
};