class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int n = matrix.size(), m = matrix.front().size();
        int x = 0, y = m - 1;
        while (x >= 0 && y >= 0 && x < n && y < m) {
            int val = matrix[x][y];
            if (val == target) return true;
            if (target < val) y--;
            else x++;
        }
        return false;
    }
};