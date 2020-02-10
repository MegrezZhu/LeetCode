class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& A, int K) {
		int n = A.size();
		vector<int> f(n + 1, 0);
		f[0] = 0;
		for (int i = 1; i <= n; i++) {
			int maxx = -1e9;
			f[i] = -1e9;
			for (int j = i; i - j + 1 <= K && j > 0; j--) {
				maxx = max(maxx, A[j - 1]);
				f[i] = max(f[i], f[j - 1] + (i - j + 1) * maxx);
			}
		}
		return f[n];
	}
};