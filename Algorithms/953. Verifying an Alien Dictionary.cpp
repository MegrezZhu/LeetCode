class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rev(26);
        for (int i = 0; i < 26; i++) rev[order[i] - 'a'] = i;
        for (int i = 0; i < words.size() - 1; i++) {
            if (!compare(words[i], words[i + 1], rev)) return false;
        }
        return true;
    }
    bool compare(const string &a, const string &b, const vector<int> &rev) {
        for (int i = 0; i < min(a.length(), b.length()); i++) {
            if (rev[a[i] - 'a'] < rev[b[i] - 'a']) return true;
            if (rev[a[i] - 'a'] > rev[b[i] - 'a']) return false;
        }
        return a.length() <= b.length();
    }
};