class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		static const int MAX_DIGIT = 30;
		int result = 0;
		for (int i = 0; i <= MAX_DIGIT; i++) {
			if ((m & (1 << i)) == 0) continue;

			int mask = (1 << i) - 1;
			int span = (1 << i) - (m & mask);
			if (m > n - span) {
				result += (1 << i);
			}
		}
		return result;
	}
};