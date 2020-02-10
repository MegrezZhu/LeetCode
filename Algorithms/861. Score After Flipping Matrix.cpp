class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size(), m = A.front().size();
        for (int i = 0; i < n; i++) {
            if (A[i][0] == 0) {
                for (int j = 0; j < m; j++) A[i][j] = 1 - A[i][j];
            }
        }
        int sum = 0;
        for (int j = 0; j < m; j++) {
            int one = 0;
            for (int i = 0; i < n; i++) {
                if (A[i][j] == 1) one++;
            }
            sum += max(one, n - one) * (1 << (m - j - 1));
        }
        return sum;
    }
};