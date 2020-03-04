class Solution {
public:
    int scoreOfParentheses(string S) {
        return compute(S, 0, S.length() - 1);
    }
    
    int compute(const string &s, int l, int r) {
        if (l + 1 == r) return 1; // ()
        
        int count = 1, p = l;
        while (count != 0) {
            p++;
            count += s[p] == '(' ? 1 : -1;
        }
        
        if (p == r) {
            return 2 * compute(s, l + 1, r - 1);
        } else {
            return compute(s, l, p) + compute(s, p + 1, r);
        }
        
        return -1e9;
    }
};