class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, n = arr.size();
        int maxx = -1, cover = 0;
        int mfin = 0;
        for (int i = 0; i < n; i++) {
            maxx = max(maxx, arr[i]);
            cover++;
            if (cover + mfin == maxx + 1) {
                ans++;
                cover = 0;
                mfin = maxx + 1;
                maxx = -1;
            }
        }
        return ans;
    }
};