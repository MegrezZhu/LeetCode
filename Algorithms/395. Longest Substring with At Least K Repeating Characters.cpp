class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        for (int i = 1; i < 26; i++) {
            ans = max(ans, solve(s, k, i));
        }
        return ans;
    }
    
    int solve(const string &s, int k, int u) {
        int uni = 0, good = 0;
        vector<int> count(26, 0);
        int ans = 0;
        for (int l = 0, r = 0; r < s.length(); r++) {
            int a = s[r] - 'a';
            if (count[a] > 0) {
                count[a]++;
                if (count[a] == k) {
                    good++;
                }
            } else {
                if (uni == u) {
                    while (true) {
                        int a = s[l++] - 'a';
                        count[a]--;
                        if (count[a] == k - 1) {
                            good--;
                        }
                        if (count[a] == 0) {
                            uni--;
                            break;
                        }
                    }
                }
                count[a]++;
                uni++;
                if (count[a] == k) {
                    good++;
                }
            }
            
            if (good == uni && uni == u) {
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};