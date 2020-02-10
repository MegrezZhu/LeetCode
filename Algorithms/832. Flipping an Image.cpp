class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size(), m = A.front().size();
        for (int i = 0; i < n; i++) {
            int l = 0, r = m - 1;
            while (l < r) {
                swap(A[i][l], A[i][r]);
                l++;
                r--;
            }
            for (int j = 0; j < m; j++) A[i][j] = 1 - A[i][j];
        }
        return A;
    }
};