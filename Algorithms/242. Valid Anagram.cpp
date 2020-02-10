class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> ss(26);
        int count = 0;
        for (char c : s) {
            if (!ss[c - 'a']) count++;
            ss[c - 'a']++;
        }
        for (char c : t) {
            if (!ss[c - 'a']) count++;
            ss[c - 'a']--;
            if (!ss[c - 'a']) count--;
        }
        return count == 0;
    }
};