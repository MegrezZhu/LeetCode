class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 1, r = 1e9;
        int ans = 2e9;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (maxBouquet(bloomDay, mid, k) >= m) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans != 2e9 ? ans : -1;
    }
    
    int maxBouquet(const vector<int> &bloomDay, int day, int len) {
        int count = 0;
        for (int i = 0, left = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                if (i - left + 1 >= len) {
                    count++;
                    left = i + 1;
                }
            } else {
                left = i + 1;
            }
        }
        return count;
    }
};