class Solution {
public:
    int maxDotProduct(const vector<int>& nums1, const vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> f(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[i][j] = nums1[i] * nums2[j] + ((i > 0 && j > 0) ? max(f[i - 1][j - 1], 0) : 0);
                if (i > 0) {
                    f[i][j] = max(f[i][j], f[i - 1][j]);
                }
                if (j > 0) {
                    f[i][j] = max(f[i][j], f[i][j - 1]);
                }
                if (i > 0 && j > 0) {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1]);
                }
            }
        }
        return f[n - 1][m - 1];
    }
};