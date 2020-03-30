class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        unordered_set<int> s = { stones[0] };
        for (int i = 1; i < stones.size(); i++) {
            unordered_set<int> s1;
            for (int sum : s) {
                s1.insert(sum + stones[i]);
                s1.insert(sum - stones[i]);
            }
            s = move(s1);
        }
        
        int ans = 1e9;
        for (int sum : s) {
            ans = min(ans, abs(sum));
        }
        return ans;
    }
};