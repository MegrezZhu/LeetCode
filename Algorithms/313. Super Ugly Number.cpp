class Solution {
public:
	int nthSuperUglyNumber(int n, const vector<int>& primes) {
		set<int> s = { 1 };
		while (--n) {
			int top = *s.begin();
			s.erase(s.begin());
			for (int p : primes) {
				if ((2147483647 / p) >= top) {
					s.insert(top * p);
				} else {
					break;
				}
				if (top % p == 0) {
					break;
				}
			}
		}
		return *s.begin();
	}
};