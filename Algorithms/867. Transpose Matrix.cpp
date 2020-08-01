class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int n = A.size(), m = A.front().size();
        vector<vector<int>> B(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                B[j][i] = A[i][j];
            }
        }
        return B;
    }
};