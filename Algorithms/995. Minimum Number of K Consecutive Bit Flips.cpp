class Solution {
public:
	int minKBitFlips(const vector<int>& A, int K) {
		int n = A.size(), count = 0;
		vector<int> flipFlags(n + 1, 0);
		for (int i = 0, flips = 0; i < n; i++) {
			flips += flipFlags[i];
			int v = A[i];
			if (flips % 2 == 1) {
				v = 1 - v;
			}
			if (v != 1) {
				if (i + K - 1 < n) {
					flipFlags[i + 1] += 1;
					flipFlags[i + K] -= 1;
					count++;
				}
				else {
					return -1;
				}
			}
		}
		return count;
	}
};