class Solution {
public:
    string removeDuplicates(string S) {
        vector<char> stk;
        
        for (char c : S) {
            if (!stk.empty() && stk.back() == c) {
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }
        
        return string(stk.begin(), stk.end());
    }
};