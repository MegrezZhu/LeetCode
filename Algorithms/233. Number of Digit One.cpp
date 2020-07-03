class Solution {
	int numDigit(int n) {
		// equals floor(log(n) / log(10))
		int d = 0;
		while (n) {
			n /= 10;
			d++;
		}
		return d - 1;
	}
public:
	int countDigitOne(int n) {
		if (n <= 0) return 0;
		else if (n < 10) return 1;

		int d = numDigit(n); // index of highest digit, starting from 0
		int hi = n / int(pow(10, d)); // highest digit, 1 ~ 9
		int count = 0;

		count += hi * (d * pow(10, d - 1));
		if (hi == 1) {
			count += n - pow(10, d) + 1;
		}
		else {
			count += pow(10, d);
		}

		return count + countDigitOne(n - hi * pow(10, d));
	}
};