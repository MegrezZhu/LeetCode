class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0) return true;
        if (t.length() == 0) return false;
        int n = s.length(), m = t.length();
        int i = n - 1;
        for (int j = m - 1; j >= 0; j--) {
            if (t[j] == s[i]) {
                if (i == 0) return true;
                i--;
            }
        }
        return false;
    }
};