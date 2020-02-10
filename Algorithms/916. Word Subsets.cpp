class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> freq(26, 0);
        for (const auto &s : B) {
            auto v = count(s);
            for (int i = 0; i < 26; i++) freq[i] = max(freq[i], v[i]);
        }
        vector<string> res;
        for (const auto &s : A) {
            auto v = count(s);
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (v[i] < freq[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(s);
            }
        }
        return res;
    }
    
    vector<int> count(const string &s) {
        vector<int> v(26, 0);
        for (char a : s) v[a - 'a']++;
        return v;
    }
};