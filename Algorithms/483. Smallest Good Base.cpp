class Solution {
	typedef unsigned long long ull;

	/*
		0 for yes, 1 for greater, -1 for smaller
		@pragma len: number of 1s
	*/
	int check(ull base, int len, ull target) {
		ull res = 1;
		while (--len) {
			if (ull(res * base) / base != res) return 1; // overflow
			res = res * base + 1;
		}
		if (res > target) return 1;
		if (res < target) return -1;
		return 0;
	}
public:
	string smallestGoodBase(string n) {
		ull target = stoull(n);
		ull ans = -1; // indicate max

		for (int len = 1; len <= 63; len++) {
			ull l = 2, r = target - 1;
			while (l <= r) {
				ull m = (l + r) / 2;
				int res = check(m, len, target);
				if (res == 0) {
					ans = min(ans, m);
					break;
				}
				if (res == -1) l = m + 1;
				else r = m - 1;
			}
		}

		return to_string(ans);
	}
};