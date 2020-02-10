class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int limit = floor(nums.size() / 2);
        while (true) {
            int v = nums[nums.size() * (rand() / float(RAND_MAX))];
            if (count(nums.begin(), nums.end(), v) > limit) return v;
        }
    }
};