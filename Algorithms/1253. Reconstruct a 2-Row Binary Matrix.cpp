class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> res(2, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 0) {
                res[0][i] = res[1][i] = 0;
            } else if (colsum[i] == 2) {
                res[0][i] = res[1][i] = 1;
                upper -= 1;
                lower -= 1;
            }
        }
        if (upper < 0 || lower < 0) return {};
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 1) {
                if (upper) {
                    res[0][i] = 1;
                    res[1][i] = 0;
                    upper -= 1;
                } else if (lower) {
                    res[0][i] = 0;
                    res[1][i] = 1;
                    lower -= 1;
                } else return {};
            }
        }
        if (!upper && !lower) {
            return res;
        } else {
            return {};
        }
    }
};