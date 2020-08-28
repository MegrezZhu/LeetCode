class Solution {
public:
    int maxFreq(const string &s, int maxLetters, int minSize, int maxSize) {
        int len = minSize;
        unordered_map<string, int> mp;
        int ans = 0;
        vector<int> count(26, 0);
        int wordCount = 0;
        for (int l = 0, r = 0; r < s.length(); r++) {
            if (count[s[r] - 'a']++ == 0) wordCount++;
            if (r - l + 1 > len) {
                if (--count[s[l++] - 'a'] == 0) {
                    wordCount--;
                }
            }
            if (r - l + 1 == len && wordCount <= maxLetters) {
                auto sub = s.substr(l, len);
                ans = max(++mp[sub], ans);
            }
        }
        return ans;
    }
};