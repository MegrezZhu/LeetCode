class Solution {
    vector<int> origin;
public:
    Solution(vector<int> nums) {
        origin = move(nums);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto res = origin;
        int n = res.size();
        for (int i = 0; i < n; i++) {
            int pos = rand() % (n - i) + i;
            swap(res[i], res[pos]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */