class Solution {
public:
	vector<int> grayCode(int n) {
		if (n <= 0) return { 0 };
		vector<int> res(pow(2, n));
		res[0] = 0;
		res[1] = 1;
		for (int i = 2, size = 2; i <= n; i++, size *= 2) {
			for (int j = 0; j < size; j++) {
				res[size + j] = res[size - j - 1] | size;
			}
		}
		return res;
	}
};