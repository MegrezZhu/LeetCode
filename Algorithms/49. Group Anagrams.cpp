class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const auto &str: strs) {
            auto _str = str;
            sort(_str.begin(), _str.end());
            auto it = mp.find(_str);
            if (it == mp.end()) mp.insert(make_pair(_str, vector<string>({ str })));
            else it->second.push_back(str);
        }
        vector<vector<string>> res;
        for (auto &p : mp) {
            res.push_back(p.second);
        }
        return res;
    }
};