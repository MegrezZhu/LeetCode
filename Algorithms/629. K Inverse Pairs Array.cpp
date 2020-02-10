class Solution {
public:
	int kInversePairs(int n, int k) {
		constexpr int MOD = 1e9 + 7;

		vector<int> f(k + 1);
		f[0] = 1;

		for (int i = 2; i <= n; i++) {
			int p = k + 1, sum = 0;
			for (int j = k; j > 0; j--) {
				while (p - 1 >= 0 && p - 1 >= j - i + 1) sum = (sum + f[--p]) % MOD;
				int tmp = f[j];
				f[j] = sum;
				sum = (sum + MOD - tmp) % MOD;
			}
		}

		return f[k];
	}
};