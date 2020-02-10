class Solution {
public:
	int lenLongestFibSubseq(vector<int>& A) {
		int ans = 0, n = A.size();
		vector<vector<int>> f(n, vector<int>(n, 0));
		for (int i = 1; i < n; i++) {
			int k = i - 1;
			for (int j = 0; j < i; j++) {
				f[j][i] = max(f[j][i], 2);
				while (j < k && A[j] + A[k] > A[i]) k--;
				if (j == k || A[j] + A[k] < A[i]) continue;
				f[k][i] = max(f[k][i], f[j][k] + 1);
				ans = max(ans, f[k][i]);
			}
		}
		return ans;
	}
};