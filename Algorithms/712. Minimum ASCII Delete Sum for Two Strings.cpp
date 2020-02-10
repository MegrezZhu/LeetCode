class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<int> f(s2.length() + 1);
        f[0] = 0;
        for (int i = 1; i <= s2.length(); i++) f[i] = f[i - 1] + s2[i - 1];
        for (int i = 1; i <= s1.length(); i++) {
            int last = f[0];
            f[0] += s1[i - 1];
            for (int j = 1; j <= s2.length(); j++) {
                int tmp = 2147483647;
                if (s1[i - 1] == s2[j - 1]) tmp = min(tmp, last);
                tmp = min(tmp, f[j] + s1[i - 1]);
                tmp = min(tmp, f[j - 1] + s2[j - 1]);
                last = f[j];
                f[j] = tmp;
            }
        }
        return f[s2.length()];
    }
};