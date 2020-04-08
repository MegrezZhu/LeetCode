class Solution {
public:
	double largestSumOfAverages(const vector<int>& A, int K) {
		int n = A.size();
		vector<vector<double>> f(n + 1, vector<double>(K + 1, -1e9));

		f[0][0] = .0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= min(i, K); j++) {
				double sum = 0;
				for (int k = i - 1; k >= j - 1; k--) {
					sum += A[k];
					f[i][j] = max(f[i][j], f[k][j - 1] + sum / (i - k));
				}
			}
		}

		return f[n][K];
	}
};