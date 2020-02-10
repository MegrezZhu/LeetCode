class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int res = 0;
		for (int i = 2, pos = 0; i < A.size(); i++) {
			while (pos + 1 < i && A[i] - A[i - 1] != A[pos + 1] - A[pos]) pos++;
			res += i - pos - 1;
		}
		return res;
	}
};