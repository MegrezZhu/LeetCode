class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        if (S == 0) {
            int ans = 0, zero = 0;
            for (int i = 0; i < A.size(); i++) {
                if (A[i] == 0) zero++;
                else {
                    ans += (1 + zero) * zero / 2;
                    zero = 0;
                }
            }
            if (zero) ans += (1 + zero) * zero / 2;
            return ans;
        }
        vector<pair<int, int>> margin;
        int zero = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == 0) zero++;
            else {
                if (!margin.empty()) {
                    margin.back().second = zero;
                }
                margin.push_back({zero, 0});
                zero = 0;
            }
        }
        if (margin.empty()) return 0;
        else margin.back().second = zero;
        int ans = 0;
        for (int i = 0; i < margin.size(); i++) {
            int j = i + S - 1;
            if (j >= margin.size()) break;
            ans += (margin[i].first + 1) * (margin[j].second + 1);
        }
        return ans;
    }
};