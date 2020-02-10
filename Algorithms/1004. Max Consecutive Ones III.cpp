class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int count = 0, ans = 0;
        for (int l = 0, r = 0; r < A.size(); r++) {
            if (A[r] == 0) count++;
            while (count > K) {
                if (A[l++] == 0) count--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};