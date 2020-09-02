class Solution {
public:
    int hIndex(const vector<int>& citations) {
        int n = citations.size();
        int ans = 0;
        int l = 1, r = n;
        while (l <= r) {
            int h = (l + r) / 2;
            if (citations[n - h] >= h) {
                ans = max(ans, h);
                l = h + 1;
            } else {
                r = h - 1;
            }
        }
        return ans;
    }
};