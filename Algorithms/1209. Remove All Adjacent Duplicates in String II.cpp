class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stk;
        
        for (char c : s) {
            if (!stk.empty() && stk.back().first == c) {
                if (stk.back().second == k - 1) {
                    while (!stk.empty() && stk.back().first == c) {
                        stk.pop_back();
                    }
                } else {
                    stk.push_back({c, stk.back().second + 1});
                }
            } else {
                stk.push_back({c, 1});
            }
        }
        
        string ret;
        for (const auto &p : stk) {
            ret.push_back(p.first);
        }
        return ret;
    }
};