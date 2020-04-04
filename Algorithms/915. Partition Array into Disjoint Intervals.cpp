class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size();
        vector<int> minn(n, 1e9);
        for (int i = n - 2; i >= 0; i--) {
            minn[i] = min(minn[i + 1], A[i + 1]);
        }
        for (int i = 0, maxx = -1; i < n - 1; i++) {
            maxx = max(maxx, A[i]);
            if (maxx <= minn[i]) {
                return i + 1;
            }
        }
        
        return -1;
    }
};