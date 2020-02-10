#include <initialize_list>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++) {
            int toFind = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == toFind) {
                    return {i, j};
                }
            }
        }
    }
};