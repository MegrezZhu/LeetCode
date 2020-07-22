class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int v : left) {
            ans = max(ans, v);
        }
        for (int v : right) {
            ans = max(ans, n - v);
        }
        return ans;
    }
};