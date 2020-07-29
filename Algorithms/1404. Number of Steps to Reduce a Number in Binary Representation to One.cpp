class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        int p = s.length() - 1;
        while (p > 0) {
            if (s[p] == '0') {
                count++;
                p--;
            } else {
                int q = p;
                while (q > 0 && s[q - 1] == '1') q--;
                count += 1 + (p - q + 1);
                if (q > 0) {
                    s[q - 1] = '1';
                }
                p = q - 1;
            }
        }
        return count;
    }
};