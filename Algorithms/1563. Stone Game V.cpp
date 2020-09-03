class Solution {
    vector<vector<int>> f;
public:
    int stoneGameV(const vector<int>& stoneValue) {
        int n = stoneValue.size();
        f = vector<vector<int>>(n, vector<int>(n, -1));
        return maxVal(stoneValue, 0, n - 1);
    }
private:
    int maxVal(const vector<int>& stone, int l, int r) {
        if (l >= r) return 0;
        if (f[l][r] == -1) {
            int sum = 0;
            for (int i = l; i <= r; i++) sum += stone[i];
            int lsum = 0, rsum = sum;
            f[l][r] = 0;
            for (int i = l; i < r; i++) {
                lsum += stone[i];
                rsum -= stone[i];
                if (lsum < rsum) {
                    f[l][r] = max(f[l][r], lsum + maxVal(stone, l, i));
                } else if (lsum > rsum) {
                    f[l][r] = max(f[l][r], maxVal(stone, i + 1, r) + rsum);
                } else {
                    f[l][r] = max(f[l][r], lsum + max(maxVal(stone, l, i), maxVal(stone, i + 1, r)));
                }
            }
        }
        return f[l][r];
    }
};