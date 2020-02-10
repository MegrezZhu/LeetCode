class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int> tmp;
        if (s.length() <= 12) {
            find(ans, s, tmp, -1);
        }
        return ans;
    }
    void find(vector<string> &ans, const string &str, vector<int> &s, int pos) {
        if (s.size() == 4 && pos == str.length() - 1) {
            ans.push_back(stringify(s));
            return;
        }
        for (int len = 1; len <= 3; len++) {
            if (pos + len < str.length()) {
                int digits = 0;
                for (int i = pos + 1; i <= pos + len; i++) digits = digits * 10 + str[i] - '0';
                if (digits < 256 && (len == 1 || str[pos + 1] != '0')) {
                    s.push_back(digits);
                    find(ans, str, s, pos + len);
                    s.pop_back();
                }
            }
        }
    }
    string stringify(const vector<int> &s) {
        static char buffer[20];
        sprintf(buffer, "%d.%d.%d.%d", s[0], s[1], s[2], s[3]);
        return buffer;
    }
};