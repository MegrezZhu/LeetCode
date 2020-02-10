class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<int> s; // 0 for (, 1 for )
        int count = 0;
        for (char c : S) {
            if (c == '(') s.push(0);
            else {
                if (!s.empty() && s.top() == 0) s.pop();
                else count++;
            }
        }
        return count + s.size();
    }
};