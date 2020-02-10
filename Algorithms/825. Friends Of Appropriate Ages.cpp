class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        sort(ages.begin(), ages.end());
        for (int i = 0, dup = 1, j = 0; i < ages.size(); i++) {
            if (i + 1 < ages.size() && ages[i] == ages[i + 1]) {
                dup++;
                continue;
            }
            int lower = ages[i] / 2 + 7;
            while (j < i && ages[j] <= lower) j++;
            ans += dup * (i - j);
            dup = 1;
        }
        return ans;
    }
};