class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        map<string, int> s;
        vector<vector<string>> ans;
        for (const auto &prod : products) {
            s[prod]++;
        }
        for (int i = 0; i < searchWord.length(); i++) {
            char c = searchWord[i];
            auto it = s.begin();
            while (it != s.end()) {
                const auto &str = it->first;
                if (i >= str.length() || str[i] != c) {
                    s.erase(it++);
                } else {
                    it++;
                }
            }
            vector<string> res;
            for (auto it = s.begin(); it != s.end() && res.size() < 3; it++) {
                for (int j = 0; j < it->second && res.size() < 3; j++) {
                    res.push_back(it->first);
                }
            }
            ans.push_back(move(res));
        }
        return ans;
    }
};