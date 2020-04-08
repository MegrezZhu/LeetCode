class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> minn(n, 1e9);
        for (int i = n - 2; i >= 0; i--) {
            minn[i] = min(minn[i + 1], arr[i + 1]);
        }
        
        int ans = 0;
        for (int i = 0, maxx = -1e9; i < n; i++) {
            maxx = max(maxx, arr[i]);
            if (maxx <= minn[i]) {
                ans++;
                maxx = -1e9;
            }
        }
        return ans;
    }
};