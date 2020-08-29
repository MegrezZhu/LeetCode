class Solution {
	using LL = long long;
public:
	int reverse(int x) {
		LL rev = _reverse(x);
		if (rev <= -2147483648LL || rev > 2147483647LL) return 0;
		return rev;
	}

	LL _reverse(int x) {
		if (x == -2147483648LL) return 0;
		if (x < 0) return -_reverse(-x);
		if (x < 10) return x;
		LL d = pow(10, int(log10(x)));
		LL lo = x % 10;
		return lo * d + _reverse(x / 10);
	}
};