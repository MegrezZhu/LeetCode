class Solution {
public:
	bool isPowerOfFour(int num) {
		while (num > 1 && ((num & 0b011) == 0)) num >>= 2;
		return num == 1;
	}
};