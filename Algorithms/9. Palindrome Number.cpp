class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int deg = pow(10, floor(log10(x)));
		while (deg) {
			if (x / deg != x % 10) return false;
			x = (x - x / deg * deg) / 10;
			deg /= 100;
		}
		return true;
	}
};