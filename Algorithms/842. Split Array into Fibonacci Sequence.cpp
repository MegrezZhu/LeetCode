class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        int n = S.length();
        
        for (int i = 1; i * 2 <= n; i++) {
            for (int j = 1; i + j <= n; j++) {
                auto res = split(S, i, j);
                if (res.size() >= 3) {
                    return res;
                }
            }
        }
        
        return {};
    }
    
    vector<int> split(const string S, int len1, int len2) {
        int n = S.length();
        if ((len1 > 1 && S[0] == '0') || (len2 > 1 && S[len1] == '0')) return {};
        if (len1 > 10 || len2 > 10) return {};
        long long x = stoll(S.substr(0, len1)), y = stoll(S.substr(len1, len2));
        if (x > 2147483647 || y > 2147483647) return {};
        vector<int> res = {int(x), int(y)};
        
        int pos = len1 + len2;
        long long t = 0;

        int digit = 0;
        bool leadingZero = false;
        while (pos < n) {
            t = t * 10 + (S[pos] - '0');
            if (t > 2147483647) return {};
            if (t == x + y) {
                res.push_back(t);
                x = y;
                y = t;
                t = 0;
                
                pos += 1;
                if (pos == n) {
                    return res;
                } else if (S[pos] == '0' && x + y != 0) {
                    return {};
                }
            } else if (t > x + y) {
                return {};
            } else if (pos + 1 == n) {
                return {};
            } else {
                pos += 1;
            }
        }
        return res;
    }
};