class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        vector<int> flag(n + 1, 0);
        
        for (const auto &booking : bookings) {
            int amount = booking[2];
            flag[booking[0] - 1] += amount;
            flag[booking[1]] -= amount;
        }
        
        for (int i = 0, count = 0; i < n; i++) {
            count += flag[i];
            ans[i] = count;
        }
        
        return ans;
    }
};