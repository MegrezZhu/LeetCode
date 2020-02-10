class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        unordered_map<int, int> window;
        int ans = 0;
        for (int i = 0, l = 0, mult = 1, type = 0; i < A.size(); i++) {
            auto &v = window[A[i]];
            v++;
            if (v == 1) type++;
            while (type >= K) {
                auto &v = window[A[l]];
                if (type > K || v > 1) {
                    v--;
                    if (v) mult++;
                    else {
                        type--;
                        mult = 1;
                        window.erase(A[l]);
                    }
                    l++;
                } else break;
            }
            if (type == K) ans += mult;
        }
        return ans;
    }
};