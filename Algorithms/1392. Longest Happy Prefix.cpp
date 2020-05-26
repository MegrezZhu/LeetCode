class Solution {
public:
    string longestPrefix(string s) {
        int len = s.length();
        vector<int> f(len, -1);
        
        for (int i = 1, j = -1; i < len; i++) {
            while (true) {
                if (s[i] == s[j + 1]) {
                    f[i] = j + 1;
                    j++;
                    break;
                } else if (j != -1) {
                    j = f[j];
                } else {
                    break;
                }
            }
        }
        
        return s.substr(0, f[len - 1] + 1);
    }
};