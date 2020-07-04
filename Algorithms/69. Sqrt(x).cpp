class Solution {
public:
	int mySqrt(int x) {
		static const double EPS = 1e-2;
		double t = 1.0;
		while (fabs(x - t * t) >= EPS) {
			t = (t + x / t) / 2.0;
		}
		return int(t);
	}
};