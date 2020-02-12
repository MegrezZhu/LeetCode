class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (r * c != nums.size() * nums.front().size()) return nums;
        vector<vector<int>> res(r, vector<int>(c));
        int x = 0, y = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] = nums[x][y];
                y++;
                if (y == nums.front().size()) {
                    y = 0;
                    x++;
                }
            }
        }
        return res;
    }
};