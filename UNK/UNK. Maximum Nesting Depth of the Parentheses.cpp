class Solution {
public:
    int maxDepth(const string &s) {
        int d = 0;
        int ans = 0;
        for (char c : s) {
            if (c == '(') {
                d++;
            } else if (c == ')') {
                d--;
            }
            ans = max(d, ans);
        }
        return ans;
    }
};