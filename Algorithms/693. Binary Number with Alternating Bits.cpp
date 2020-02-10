class Solution {
public:
	bool hasAlternatingBits(int n) {
		bool last = n % 2 == 1;
		n /= 2;
		while (n) {
			if (!((n % 2 == 1) ^ last)) return false;
			last = n % 2 == 1;
			n /= 2;
		}
		return true;
	}
};