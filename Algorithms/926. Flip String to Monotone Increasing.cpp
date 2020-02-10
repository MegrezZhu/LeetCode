class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        vector<int> zero(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            zero[i] = zero[i + 1];
            if (S[i + 1] == '0')  zero[i]++;
        }
        int ans = zero[0] + int(S[0] == '0');
        for (int i = 0, count = 0; i < n; i++) {
            if (S[i] == '1') count++;
            ans = min(ans, count + zero[i]);
        }
        return ans;
    }
};