class Solution {
public:
    int constrainedSubsetSum(const vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n, -2e9);
        list<int> q;
        
        int ans = -2e9;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.front() < i - k) {
                q.pop_front();
            }
            f[i] = (q.empty() ? 0 : f[q.front()]) + nums[i];
            if (f[i] > 0) {
                while (!q.empty() && f[q.back()] <= f[i]) {
                    q.pop_back();
                }
                q.push_back(i);
            }
            
            ans = max(ans, f[i]);
        }
        return ans;
    }
};