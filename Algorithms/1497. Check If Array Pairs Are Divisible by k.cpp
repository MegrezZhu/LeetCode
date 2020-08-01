class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> pool(k, 0);
        for (int x : arr) {
            pool[(x % k + k) % k]++;
        }
        if (k % 2 == 0) {
            if (pool[k / 2] % 2 != 0) return false;
        }
        if (pool[0] % 2 != 0) return false;
        for (int i = 1; k - i > i; i++) {
            if (pool[i] != pool[k - i]) return false;
        }
        return true;
    }
};