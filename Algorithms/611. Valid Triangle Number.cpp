class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for (auto i = nums.begin(); nums.end() - i > 2; i++) {
            int a = *i;
            if (a == 0) continue;
            for (auto j = i + 1; nums.end() - j > 1; j++) {
                int b = *j;
                int upper = a + b - 1, lower = b - a + 1;
                auto low = lower_bound(j + 1, nums.end(), lower);
                auto high = upper_bound(j + 1, nums.end(), upper);
                count += high - low;
            }
        }
        return count;
    }
};