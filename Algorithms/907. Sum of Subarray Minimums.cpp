class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int ans = 0, sum = 0;
        int MOD = 1e9 + 7;
        stack<pair<int, int>> s;
        s.push({int(-1e9), -1});
        for (int i = 0; i < A.size(); i++) {
            while (A[i] <= s.top().first) {
                auto top = s.top();
                s.pop();
                sum = (sum - top.first * (top.second - s.top().second) + MOD) % MOD;
            }
            sum = (sum + A[i] * (i - s.top().second)) % MOD;
            s.push({A[i], i});
            ans = (ans + sum) % MOD;
        }
        return ans;
    }
};