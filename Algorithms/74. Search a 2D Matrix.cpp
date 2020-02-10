class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int n = matrix.size(), m = matrix.front().size();
        int l = 0, r = n * m - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int val = get(matrix, m);
            if (target == val) return true;
            if (target < val) r = m - 1;
            else l = m + 1;
        }
        return false;
    }
    int get(const vector<vector<int>> &matrix, int id) {
        int m = matrix.front().size();
        int x = id / m, y = id % m;
        return matrix[x][y];
    }
};