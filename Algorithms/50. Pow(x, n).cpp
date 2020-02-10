class Solution {
public:
    double myPow(double x, long n) {
        if (n == 0) return 1.;
        if (n == 1) return x;
        if (n < 0) return 1. / myPow(x, -n);
        double mid = myPow(x, n / 2);
        return mid * mid * myPow(x, n % 2);
    }
};