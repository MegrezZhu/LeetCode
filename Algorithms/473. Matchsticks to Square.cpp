class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = 0;
        for (int a : nums) sum += a;
        if (sum % 4 || !sum) return false;
        
        sort(nums.begin(), nums.end());
        vector<int> state(4, 0);
        int len = sum / 4;
        return find(nums, state, 0, len);
    }
    
    bool find(const vector<int> &nums, vector<int> &state, int L, int limit) {
        if (L == nums.size()) return true;
        for (int i = 0; i < 4; i++) {
            if (state[i] + nums[L] <= limit) {
                int left = limit - state[i] - nums[L];
                if (L < nums.size() - 1 && left && left < nums[L + 1]) continue;
                state[i] += nums[L];
                if (find(nums, state, L + 1, limit)) return true;
                state[i] -= nums[L];
            }
        }
        return false;
    }
};