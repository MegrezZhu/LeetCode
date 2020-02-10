class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        for (int q : b) {
            ans = normalPow(ans, 10);
            ans = (ans * normalPow(a % 1337, q)) % 1337;
        }
        return ans;
    }
    int normalPow(int a, int q) {
        if (q == 0) return 1;
        if (q == 1) return a % 1337;
        int mid = normalPow(a, q / 2);
        if (q % 2) return (long(mid) * mid * a) % 1337;
        else return (long(mid) * mid) % 1337;
    }
};