class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int m1 = -1, m2 = -1;
        int ind;
        for (int i = 0; i < nums.size(); i++) {
            int v = nums[i];
            if (v >= m1) {
                m2 = m1;
                m1 = v;
                ind = i;
            } else if (v > m2) {
                m2 = v;
            }
        }
        return m1 >= 2 * m2 ? ind : -1;
    }
};