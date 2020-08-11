class Solution {
public:
    int maximumSum(const vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> f(n, vector<int>(2, -1e9)); 
        f[0][0] = arr[0];
        int ans = f[0][0];
        for (int i = 1; i < n; i++) {
            f[i][0] = max(f[i - 1][0], 0) + arr[i];
            f[i][1] = max(f[i - 1][0], max(f[i - 1][1], 0) + arr[i]);
            
            ans = max(ans, max(f[i][0], f[i][1]));
        }
        return ans;
    }
};