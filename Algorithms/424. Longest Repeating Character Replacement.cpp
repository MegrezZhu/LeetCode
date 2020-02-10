class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<bool> tested(26, false);
        int ans = 0;
        for (char target : s) {
            if (tested[target - 'A']) continue;
            tested[target - 'A'] = true;
            
            int left = k;
            int f = 0, r = -1;
            while (r + 1 < s.length()) {
                r++;
                if (s[r] != target) {
                    left--;
                    while (left < 0) {
                        if (s[f++] != target) left++;
                    }
                }
                ans = max(ans, r - f + 1);
            }
        }
        return ans;
    }
};