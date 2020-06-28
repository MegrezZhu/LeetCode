class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        const static int MAX_TRIP_LEN = 1000;
        vector<int> modifier(MAX_TRIP_LEN + 1, 0);
        for (const auto &trip : trips) {
            int num = trip[0], start = trip[1], end = trip[2];
            modifier[trip[1]] -= num;
            modifier[trip[2]] += num;
        }
        for (int i = 0; i <= MAX_TRIP_LEN; i++) {
            capacity += modifier[i];
            if (capacity < 0) {
                return false;
            }
        }
        return true;
    }
};