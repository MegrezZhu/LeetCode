class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int sum = 0, i = 0; i < A.size(); i++) {
            sum = (((sum + A[i]) % K) + K) % K;
            mp[sum] += 1;
        }
        int ans = 0;
        for (const auto &p : mp) {
            ans += p.second * (p.second - 1) / 2;
        }
        return ans;
    }
};