class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxx = -1e9, minn = 1e9;
        for (int i : A) {
            maxx = max(maxx, i);
            minn = min(minn, i);
        }
        return max(0, maxx - minn - 2 * K);
    }
};