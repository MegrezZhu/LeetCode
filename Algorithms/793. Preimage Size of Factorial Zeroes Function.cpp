class Solution {
    using int64 = long long;
public:
    int preimageSizeFZF(int64 K) {
        int64 l = 0, r = 5 * K;
        int64 pos = r;
        while (l <= r) {
            auto mid = (l + r) / 2;
            int k = f(mid);
            if (k >= K) {
                if (k == K) pos = min(pos, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        int ans = 0;
        while (f(pos) == K) {
            ans++;
            pos++;
        }
        return ans;
    }
private:
    int f(int64 x) {
        int res = 0;
        while (x) {
            res += x / 5;
            x /= 5;
        }
        return res;
    }
};