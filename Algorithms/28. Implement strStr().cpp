class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        for (int i = 0; i < n - m + 1; i++) {
            bool res = true;
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    res = false;
                    break;
                }
            }
            if (res) return i;
        }
        return -1;
    }
};