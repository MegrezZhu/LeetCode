class Solution {
	using int64 = unsigned long long;
public:
	int superpalindromesInRange(string Ls, string Rs) {
		int base = 1, count = 0;
		int64 L = toInt(Ls), R = toInt(Rs);
		while (true) {
			// if (isSuperPali(base, L, R)) count++;
			int64 pali = makePali(base), pali1 = makePali1(base);
			if (isSuperPali(pali, L, R)) count++;
			if (isSuperPali(pali1, L, R)) count++;

			if (pali * pali > R && pali1 * pali1 > R) break;

			base++;
		}
		return count;
	}
private:
	int64 toInt(string s) {
		int64 res = 0;
		for (char ch : s) res = res * 10 + (int64(ch) - '0');
		return res;
	}
	bool isPali(int64 x) {
		if (x == 0) return true;
		static char buf[20];
		int len = 0;
		while (x) {
			buf[len++] = x % 10 + '0';
			x /= 10;
		}
		for (int i = 0; i <= len / 2; i++) {
			if (buf[i] != buf[len - i - 1]) return false;
		}
		return true;
	}
	bool isSuperPali(int64 x, int64 L = 0, int64 R = 1e19) {
		auto square = x * x;
		return isPali(x) && isPali(square) && square >= L && square <= R;
	}
	int64 makePali(int64 x) {
		auto res = x;
		while (x) {
			res = res * 10 + (x % 10);
			x /= 10;
		}
		return res;
	}
	int64 makePali1(int64 x) {
		auto res = x;
		x /= 10;
		while (x) {
			res = res * 10 + (x % 10);
			x /= 10;
		}
		return res;
	}
};