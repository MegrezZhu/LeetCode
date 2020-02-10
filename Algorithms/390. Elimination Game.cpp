class Solution {
public:
    int lastRemaining(int n, bool left = true) {
        if (n == 1) return 1;
        int last = lastRemaining(n / 2, !left);
        if (left) return last * 2;
        else return (n % 2 ? last * 2 : (last * 2 - 1));
    }
};